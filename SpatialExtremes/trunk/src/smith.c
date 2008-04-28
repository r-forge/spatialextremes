#include "header.h"

void smithfull(double *data, double *distVec, int *nSite,
	       int *nObs, double *locs, double *scales, double *shapes,
	       double *icov11, double *icov12, double *icov22, double *dns){
  //This is the Smith model. It computes the pairwise log-likelihood

  struct toFrech toFrechObj;
  struct covComp covCompObj;
  const int nPairs = *nSite * (*nSite - 1) / 2;
  int i;
  double *jac, *mahalDist;
  
  jac = (double *)R_alloc(*nSite * *nObs, sizeof(double));
  mahalDist = (double *)R_alloc(nPairs, sizeof(double));
  
  //Some preliminary steps: Valid points?
  for (i=0;i<*nSite;i++)
    if ((scales[i] <= 0) || (shapes[i] <= -1)){
      //printf("scales <= 0!!!\n");
      *dns = -1.0e35;
      return;
    }

  //Stage 1: Computing the Mahalanobis distance
  covCompObj = mahalDistFct(distVec, nPairs, icov11,
			    icov12, icov22);
  
  if (covCompObj.flag == 1){
    //printf("Problem with mahal. dist\n");
    *dns = -1.0e35;
    return;
  }

  mahalDist = covCompObj.vec;
    
  //Stage 2: Transformation to unit Frechet
  toFrechObj = gev2frech(data, *nObs, *nSite, locs, scales,
			 shapes);
    
  if (toFrechObj.flag == 1){
    //printf("problem with conversion to unit frechet\n");
    *dns = -1.0e35;
    return;
  }
  
  data = toFrechObj.frech;
  jac = toFrechObj.jac;
  
  //Stage 3: Bivariate density computations
  *dns = lpliksmith(data, mahalDist, jac, *nObs, *nSite);
}

void smithdsgnmat(double *data, double *distVec, int *nSite, int *nObs, 
		  double *locdsgnmat, double *locpenmat, int *nloccoeff,
		  int *npparloc, double *locpenalty, double *scaledsgnmat,
		  double *scalepenmat, int *nscalecoeff, int *npparscale,
		  double *scalepenalty, double *shapedsgnmat, double *shapepenmat,
		  int *nshapecoeff, int *npparshape, double *shapepenalty,
		  double *loccoeff, double *scalecoeff, double *shapecoeff,
		  double *icov11, double *icov12, double *icov22, double *dns){
  //This is the Smith model. It computes the pairwise log-likelihood
  
  struct toFrech toFrechObj;
  struct covComp covCompObj;
  struct toParam gevParam;
  const int nPairs = *nSite * (*nSite - 1) / 2;
  int i, j;
  double *jac, *mahalDist, *locs, *scales, *shapes, pen;
  
  jac = (double *)R_alloc(*nSite * *nObs, sizeof(double));
  mahalDist = (double *)R_alloc(nPairs, sizeof(double));
  locs = (double *)R_alloc(*nSite, sizeof(double));
  scales = (double *)R_alloc(*nSite, sizeof(double));
  shapes = (double *)R_alloc(*nSite, sizeof(double));
  
  //Stage 1: Computing the Mahalanobis distance
  covCompObj = mahalDistFct(distVec, nPairs, icov11, icov12,
			    icov22);

  if (covCompObj.flag == 1){
    //printf("problem with mahal. dist\n");
    *dns = -1.0e35;
    return;
  }

  mahalDist = covCompObj.vec;

  //Stage 2: Computing the GEV parameters using the design matrix
  gevParam = dsgnmat2Param(locdsgnmat, scaledsgnmat, shapedsgnmat,
			   loccoeff, scalecoeff, shapecoeff, *nSite,
			   *nloccoeff, *nscalecoeff, *nshapecoeff);

  if (gevParam.flag == 1){
    //printf("problem with the GEV parameters\n");
    *dns = -1.0e35;
    return;
  }

  locs = gevParam.locs;
  scales = gevParam.scales;
  shapes = gevParam.shapes;

  //Stage 3: Transformation to unit Frechet
  toFrechObj = gev2frech(data, *nObs, *nSite, locs, scales, shapes);
    
  if (toFrechObj.flag == 1){
    //printf("problem with conversion to unit frechet\n");
    *dns = -1.0e35;
    return;
  }
  
  data = toFrechObj.frech;
  jac = toFrechObj.jac;
  
  //Stage 4: Bivariate density computations
  *dns = lpliksmith(data, mahalDist, jac, *nObs, *nSite);
  
  if (*dns == -1.0e35){
    //printf("problem with the pairwise lik.\n");
    return;
  }

  //Stage 5: Removing the penalizing terms (if any)
  // 1- For the location parameter
  if (*locpenalty > 0)
    *dns = *dns - penalization(locpenmat, loccoeff, *locpenalty,
			       *nloccoeff, *npparloc);
 
  // 2- For the scale parameter
  if (*scalepenalty > 0)    
    *dns = *dns - penalization(scalepenmat, scalecoeff, *scalepenalty,
			       *nscalecoeff, *npparscale);
    
  // 3- For the shape parameter
  if (*shapepenalty > 0)
    *dns = *dns - penalization(shapepenmat, shapecoeff, *shapepenalty,
			       *nshapecoeff, *npparshape);

}
