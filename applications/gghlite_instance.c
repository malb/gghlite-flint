#include <gghlite/gghlite.h>
#include <gghlite/gghlite-internals.h>
#include "common.h"

int main(int argc, char *argv[]) {

  cmdline_params_t params;
  parse_cmdline(params, argc, argv, "GGHLite Instance Generator", NULL);

  print_header("GGHLite Instance Generator", params);

  flint_rand_t randstate;
  flint_randinit_seed(randstate, params->seed, 1);

  gghlite_sk_t self;
  gghlite_params_init(self->params, params->lambda, params->kappa, params->rerand, params->flags);
  gghlite_params_print(self->params);

  printf("\n---\n");

  gghlite_sk_init(self, randstate);

  printf("\n---\n");

  gghlite_sk_print_norms(self);

  printf("\n---\n");

  gghlite_sk_print_times(self);

  gghlite_sk_clear(self, 1);

  flint_randclear(randstate);
  flint_cleanup();
  mpfr_free_cache();
}
