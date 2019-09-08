
#' @title Pour créer un objet de type Random_walk
#'
#' @param sigma un double qui contient l'écart type de la marche aléatoire.
#'
#' @return un objet de class Random_walk
#' @export
#'
#' @examples create(2)
#'
create <- function(sigma){

  ok <- new(Random_walk, sigma)
  ok
}
