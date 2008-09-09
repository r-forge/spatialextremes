#include "header.h"

void smithfull(double *data, double *distVec, int *nSite,
	       int *nObs, double *locs, double *scales, double *shapes,
	       double *cov11, double *cov12, double *cov22,
	       int *fitmarge, double *dns){
  //This is the Smith model. It computes the pairwise log-likelihood

  const int nPairs = *nSite * (*nSite - 1) / 2;
  int i;
  double *jac, *mahalDist, *frech, flag = 0.0;
  
  jac = (double *)R_alloc(*nSite * *nObs, sizeof(double));
  mahalDist = (double *)R_alloc(nPairs, sizeof(double));
  frech = (double *)R_alloc(*nSite * *nObs, sizeof(double));
  
  //Some preliminary steps: Valid points?
  if (*fitmarge){
    for (i=0;i<*nSite;i++){
      if (scales[i] <= 0){
	//printf("scales <= 0!!!\n");
	*dns += R_pow_di(1 - scales[i], 2) * MINF;
      }
      
      if (shapes[i] <= -1){
	//printf("shapes <= -1!!!\n");
	*dns += R_pow_di(shapes[i], 2) * MINF;
      }
    }
  }
  
  //Stage 1: Computing the Mahalanobis distance
  flag = mahalDistFct(distVec, nPairs, cov11,
		      cov12, cov22, mahalDist);
  
  if (flag != 0.0){
    //printf("Problem with mahal. dist\n");
    *dns += flag;
  }
  
  //Stage 2: Transformation to unit Frechet
  if (*fitmarge){
    flag = gev2frech(data, *nObs, *nSite, locs, scales,
		     shapes, jac, frech);
    
    if (flag != 0.0){
      //printf("problem with conversion to unit frechet\n");
      *dns += flag;
    }
  }

  else {
    for (i=0;i<(*nSite * *nObs);i++){
      frech[i] = data[i];
      jac[i] = 0.0;    
    }
  }
    
  if (*dns == 0.0){
    //Stage 3: Bivariate density computations
    *dns = lpliksmith(frech, mahalDist, jac, *nObs, *nSite);
  }  

  return;
}

void smithdsgnmat(double *data, double *distVec, int *nSite, int *nObs, 
		  double *locdsgnmat, double *locpenmat, int *nloccoeff,
		  int *npparloc, double *locpenalty, double *scaledsgnmat,
		  double *scalepenmat, int *nscalecoeff, int *npparscale,
		  double *scalepenalty, double *shapedsgnmat, double *shapepenmat,
		  int *nshapecoeff, int *npparshape, double *shapepenalty,
		  double *loccoeff, double *scalecoeff, double *shapecoeff,
		  double *cov11, double *cov12, double *cov22, double *dns){
  //This is the Smith model. It computes the pairwise log-likelihood
  
  const int nPairs = *nSite * (*nSite - 1) / 2;
  int i, j;
  double *jac, *mahalDist, *locs, *scales, *shapes, *frech,
    flag = 0.0;
  
  jac = (double *)R_alloc(*nSite * *nObs, sizeof(double));
  mahalDist = (double *)R_alloc(nPairs, sizeof(double));
  locs = (double *)R_alloc(*nSite, sizeof(double));
  scales = (double *)R_alloc(*nSite, sizeof(double));
  shapes = (double *)R_alloc(*nSite, sizeof(double));
  frech = (double *)R_alloc(*nSite * *nObs, sizeof(double));
  
  //Stage 1: Computing the Mahalanobis distance
  flag = mahalDistFct(distVec, nPairs, cov11, cov12,
		      cov22, mahalDist);

  if (flag != 0.0){
    //printf("problem with mahal. dist\n");
    *dns = flag;
  }

  //Stage 2: Computing the GEV parameters using the design matrix
  flag = dsgnmat2Param(locdsgnmat, scaledsgnmat, shapedsgnmat,
		       loccoeff, scalecoeff, shapecoeff, *nSite,
		       *nloccoeff, *nscalecoeff, *nshapecoeff,
		       locs, scales, shapes);

  if (flag != 0.0){
    //printf("problem with the GEV parameters\n");
    *dns += flag;
  }

  //Stage 3: Transformation to unit Frechet
  flag = gev2frech(data, *nObs, *nSite, locs, scales, shapes,
		   jac, frech);
    
  if (flag != 0.0){
    //printf("problem with conversion to unit frechet\n");
    *dns += flag;
  }
  
  if (*dns == 0.0){
    //Stage 4: Bivariate density computations
    *dns = lpliksmith(frech, mahalDist, jac, *nObs, *nSite);
    
    //Stage 5: Removing the penalizing terms (if any)
    // 1- For the location parameter
    if (*locpenalty > 0)
      *dns -= penalization(locpenmat, loccoeff, *locpenalty,
			   *nloccoeff, *npparloc);
    
    // 2- For the scale parameter
    if (*scalepenalty > 0)    
      *dns -= penalization(scalepenmat, scalecoeff, *scalepenalty,
			   *nscalecoeff, *npparscale);
    
    // 3- For the shape parameter
    if (*shapepenalty > 0)
      *dns -= penalization(shapepenmat, shapecoeff, *shapepenalty,
			   *nshapecoeff, *npparshape);
  }
  
  return;
}
