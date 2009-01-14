madogram <- function(data, coord, n.bins, gev.param = c(0, 1, 0),
                     which = c("mado", "ext"), xlab, ylab,
                     angles = NULL, marge = "mle", ...){
  
  if (nrow(coord) != ncol(data))
    stop("'data' and 'coord' don't match")

  if (!is.null(angles) & !missing(n.bins))
    stop("'It is not possible to pass 'n.bins' and 'angles' at the same time")

  if (any(!(which %in% c("mado", "ext"))))
    stop("'which' must be either 'mado', 'ext' or both")

  if (!(marge %in% c("mle", "emp")))
    stop("'marge' must be either 'mle' or 'emp'")
  
  n.site <- ncol(data)
  n.obs <- nrow(data)
  n.pairs <- (n.site - 1) * n.site / 2
  dist <- distance(coord)

  if (!is.null(angles)){
    distVec <- distance(coord, vec = TRUE)
    n.angles <- length(angles)
    angles.coord <- atan2(distVec[,2], distVec[,1])

    col <- rep(NA, n.site * (n.site - 1) / 2)
    idx.angles <- list()
    for (i in 2:n.angles){
      idx <- which((angles.coord < angles[i]) & (angles.coord >= angles[i-1]))
      idx.angles <- c(idx.angles, list(idx))
      col[idx] <- i-1
    }
  }

  else
    col <- 1

  if (marge == "emp")
    ##We use the plotting-positions as defined by Hosking and Wallis (1995)
    data <- (apply(data, 2, order) - 0.35) / n.obs

  else{
    for (i in 1:n.site){
      param <- gevmle(data[,i])
      data[,i] <- pgev(data[,i], param[1], param[2], param[3])
    }
  }

  data <- qgev(data, gev.param[1], gev.param[2], gev.param[3])

  mado <- .C("madogram", as.double(data), as.integer(n.obs),
             as.integer(n.site), mado = double(n.pairs),
             PACKAGE = "SpatialExtremes")$mado

  if (!missing(n.bins)){
    bins <- c(0, quantile(dist, 1:n.bins/(n.bins + 1)), max(dist))
    madoBinned <- rep(NA, length = n.bins + 1)
      
    for (k in 1:(n.bins + 1)){
      idx <- which((dist <= bins[k+1]) & (dist > bins[k]))
      
      if (length(idx)>0)
        madoBinned[k] <- mean(mado[idx])
    }
    
    mado <- madoBinned
    dist <- (bins[-1] + bins[-(n.bins+2)])/2
  }

  if (gev.param[3] == 0)
    ext.coeff <- exp(mado/gev.param[2])

  else
    ext.coeff <- gev2frech(gev.param[1] + mado / gamma(1 - gev.param[3]),
                           gev.param[1], gev.param[2], gev.param[3])

  if (length(which) == 2){
    op <- par(mfrow=c(1,2))
    on.exit(par(op))
  }

  if (missing(xlab))
    xlab <- "h"

  if (missing(ylab))
      ylab <- c(expression(nu(h)), expression(theta(h)))
    
  if (any(which == "mado"))
    plot(dist, mado, xlab = xlab, ylab = ylab[1], col = col,
         pch = col, ...)
    
  if (any(which == "ext"))
    plot(dist, ext.coeff, xlab = xlab, ylab = ylab[2], col = col,
         pch = col, ...)

  invisible(cbind(dist = dist, madogram = mado, ext.coeff = ext.coeff))
}

fmadogram <- function(data, coord, n.bins, which = c("mado", "ext"),
                      xlab, ylab, angles = NULL, marge = "mle", ...){
  
  if (nrow(coord) != ncol(data))
    stop("'data' and 'coord' don't match")

  if (!is.null(angles) & !missing(n.bins))
    stop("'It is not possible to pass 'n.bins' and 'angles' at the same time")

  if (any(!(which %in% c("mado", "ext"))))
    stop("'which' must be either 'mado', 'ext' or both")

  if (!(marge %in% c("mle", "emp")))
    stop("'marge' must be either 'mle' or 'emp'")
  
  n.site <- ncol(data)
  n.obs <- nrow(data)
  n.pairs <- (n.site - 1) * n.site / 2
  dist <- distance(coord)

  if (!is.null(angles)){
    distVec <- distance(coord, vec = TRUE)
    n.angles <- length(angles)
    angles.coord <- atan2(distVec[,2], distVec[,1])

    col <- rep(NA, n.site * (n.site - 1) / 2)
    idx.angles <- list()
    for (i in 2:n.angles){
      idx <- which((angles.coord < angles[i]) & (angles.coord >= angles[i-1]))
      idx.angles <- c(idx.angles, list(idx))
      col[idx] <- i-1
    }
  }

  else
    col <- 1

  if (marge == "emp")
    ##We use the plotting-positions as defined by Hosking and Wallis (1995)
    data <- (apply(data, 2, order) - 0.35) / nrow(data)

  else{
    for (i in 1:n.site){
      param <- gevmle(data[,i])
      data[,i] <- pgev(data[,i], param["loc"], param["scale"], param["shape"])
    }
  }

  fmado <- .C("madogram", as.double(data), as.integer(n.obs),
              as.integer(n.site), mado = double(n.pairs),
              PACKAGE = "SpatialExtremes")$mado

  if (!missing(n.bins)){
    bins <- c(0, quantile(dist, 1:n.bins/(n.bins + 1)), max(dist))
    fmadoBinned <- rep(NA, length = n.bins + 1)
      
    for (k in 1:(n.bins+1)){
      idx <- which((dist <= bins[k+1]) & (dist > bins[k]))
      
      if (length(idx)>0)
        fmadoBinned[k] <- mean(fmado[idx])
    }
    
    fmado <- fmadoBinned
    dist <- (bins[-1] + bins[-(n.bins+2)])/2
  }

  ext.coeff <- (1 + 2 * fmado) / (1 - 2 * fmado)

  if (length(which) == 2){
    op <- par(mfrow=c(1,2))
    on.exit(par(op))
  }

  if (missing(xlab))
    xlab <- "h"

  if (missing(ylab))
      ylab <- c(expression(nu[F](h)), expression(theta(h)))
    
  if (any(which == "mado"))
    plot(dist, fmado, xlab = xlab, ylab = ylab[1], col = col,
         pch = col, ...)
  
  if (any(which == "ext"))
    plot(dist, ext.coeff, xlab = xlab, ylab = ylab[2], col = col,
         pch = col, ...)

  invisible(cbind(dist = dist, madogram = fmado, ext.coeff = ext.coeff))
}

lmadogram <- function(data, coord, n.bins, xlab, ylab, zlab, n.lambda = 11,
                      marge = "mle", col = terrain.colors(50, alpha = 0.5),
                      theta = 90, phi = 20, border = NA, ...){
  
  if (nrow(coord) != ncol(data))
    stop("'data' and 'coord' don't match")

  if (!(marge %in% c("mle", "emp")))
    stop("'marge' must be either 'mle' or 'emp'")

  n.obs <- nrow(data)
  n.site <- ncol(data)
  n.pairs <- (n.site - 1) * n.site / 2
  lambda <- seq(0, 1, length = n.lambda)
  dist <- distance(coord)

  if (marge == "emp")
    data <- (apply(data, 2, order)) / (nrow(data)+1)

  else{
    for (i in 1:n.site){
      param <- gevmle(data[,i])
      data[,i] <- pgev(data[,i], param["loc"], param["scale"], param["shape"])
    }
  }

  lmado <- .C("lmadogram", as.double(data), as.integer(n.obs),
              as.integer(n.site), as.double(lambda), as.integer(n.lambda),
              lmado = double(n.pairs * n.lambda),
              PACKAGE = "SpatialExtremes")$lmado
  lmado <- matrix(lmado, nrow = n.lambda, ncol = n.pairs)

  if (!missing(n.bins)){
    bins <- c(0, quantile(dist, 1:n.bins/(n.bins + 1)), max(dist))
    lmadoBinned <- matrix(NA, ncol = n.bins + 1, nrow = n.lambda)
    
    for (k in 1:(n.bins+1)){
      idx <- which((dist <= bins[k+1]) & (dist > bins[k]))
      
      if (length(idx) == 1)
        lmadoBinned[,k] <- lmado[,idx]

      else if (length(idx) > 1)
        lmadoBinned[,k] <- rowMeans(lmado[,idx])
    }
    
    lmado <- lmadoBinned
    dist <- (bins[-1] + bins[-(n.bins+2)])/2
  }

  else{
    ##We need to sort the pairwise distance to use the persp function
    dist <- sort(dist, index.return = TRUE)
    idx <- dist$ix
    dist <- dist$x
    lmado <- lmado[,idx]
  }
  
  if (missing(xlab))
    xlab <- "lambda"

  if (missing(ylab))
    ylab <- "h"
  
  if (missing(zlab))
    zlab <- "lambda-madogram"

  if (missing(n.bins))
    zfacet <- lmado[-1,-1] + lmado[-1, -n.pairs] + lmado[-n.lambda,-1] +
      lmado[-n.lambda, -n.pairs]

  else
    zfacet <- lmado[-1,-1] + lmado[-1, -(n.bins+1)] + lmado[-n.lambda,-1] +
      lmado[-n.lambda, -(n.bins+1)]
  
  facetcol <- cut(zfacet, length(col))

  persp(lambda, dist, lmado, xlab = xlab, ylab = ylab, zlab = zlab,
        col = col[facetcol], theta = theta, phi = phi, border = border,
        ...)

  invisible(list(lambda = lambda, dist = dist, madogram = lmado))
}