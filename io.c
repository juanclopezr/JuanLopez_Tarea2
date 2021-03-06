#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

void print_L(physics_grid *G){
  fprintf(stdout, "L_x = %f\n", G->L_x);
  fprintf(stdout, "L_y = %f\n", G->L_y);
  fprintf(stdout, "L_z = %f\n", G->L_z);
}

void print_E(int number, physics_grid *P)
{
    char name[100];
    sprintf(name, "%d_sedov.dat", number);
    FILE *energy = fopen(name, "w");
    int i, j, k, index;
    for(i = 0; i<P->N_x; i++)
    {
        for(j = 0; j<P->N_y; j++)
        {
            // for(k = 0; k<P->N_z; k++)
            // {
                index = transform3d(i, j, 0.5*P->N_z);
                fprintf(energy, "%f\n", P->P[index].E);
            // }
        }
    }
    fclose(energy);
}

void print_rho(int number, physics_grid *P)
{
    char name[100];
    sprintf(name, "%d_sedov.dat", number);
    FILE *file = fopen(name, "w");
    FLOAT *density = calc_density(*P);
    int i;
    for(i=0; i<0.5*P->N_x; i++)
    {
        fprintf(file, "%f\n", density[i]);
    }
    free(density);
    fclose(file);
}
