/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University.
 *                         All rights reserved.
 * Copyright (c) 2004-2005 The Trustees of the University of Tennessee.
 *                         All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 */

#include "ompi_config.h"

#include <stdio.h>

#include "mpi.h"
#include "mpi/f77/bindings.h"

#if OMPI_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_OPEN_PORT = mpi_open_port_f
#pragma weak pmpi_open_port = mpi_open_port_f
#pragma weak pmpi_open_port_ = mpi_open_port_f
#pragma weak pmpi_open_port__ = mpi_open_port_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_OPEN_PORT,
                           pmpi_open_port,
                           pmpi_open_port_,
                           pmpi_open_port__,
                           pmpi_open_port_f,
                           (MPI_Fint *info, char *port_name, MPI_Fint *ierr),
                           (info, port_name, ierr) )
#endif

#if OMPI_HAVE_WEAK_SYMBOLS
#pragma weak MPI_OPEN_PORT = mpi_open_port_f
#pragma weak mpi_open_port = mpi_open_port_f
#pragma weak mpi_open_port_ = mpi_open_port_f
#pragma weak mpi_open_port__ = mpi_open_port_f
#endif

#if ! OMPI_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_OPEN_PORT,
                           mpi_open_port,
                           mpi_open_port_,
                           mpi_open_port__,
                           mpi_open_port_f,
                           (MPI_Fint *info, char *port_name, MPI_Fint *ierr),
                           (info, port_name, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OMPI_HAVE_WEAK_SYMBOLS
#include "mpi/f77/profile/defines.h"
#endif

void mpi_open_port_f(MPI_Fint *info, char *port_name, MPI_Fint *ierr)
{
    MPI_Info c_info;

    c_info = MPI_Info_f2c(*info);

    *ierr = OMPI_INT_2_FINT(MPI_Open_port(c_info, port_name));
}
