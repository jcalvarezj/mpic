/*
  Este es un ejemplo basico de MPI para correr en un cluster
*/
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
  int proceso, numProcesos, largoNombre;
  char nombre[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&numProcesos);
  MPI_Comm_rank(MPI_COMM_WORLD,&proceso);
  MPI_Get_processor_name(nombre,&largoNombre);

  printf("\nHola desde el procesador numero %d+1 de %d\nSoy la maquina %s!!!!",proceso,numProcesos,nombre);
  fflush(stdout); // Para forzar que se muestre la cadena concatenada

  MPI_Finalize();
  return 0;
}
