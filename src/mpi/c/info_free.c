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

#include "mpi.h"
#include "mpi/c/bindings.h"
#include "class/ompi_list.h"
#include "info/info.h"
#include "errhandler/errhandler.h"
#include "communicator/communicator.h"

#if OMPI_HAVE_WEAK_SYMBOLS && OMPI_PROFILING_DEFINES
#pragma weak MPI_Info_free = PMPI_Info_free
#endif

#if OMPI_PROFILING_DEFINES
#include "mpi/c/profile/defines.h"
#endif

static const char FUNC_NAME[] = "MPI_Info_free";


/**
 *   MPI_Info_free - Free an 'MPI_Info' object.
 *
 *   @param info pointer to info object to be freed (handle)
 *
 *   @retval MPI_SUCCESS
 *   @retval MPI_ERR_INFO
 *
 *   Upon successful completion, 'info' will be set to 'MPI_INFO_NULL'.
 */
int MPI_Info_free(MPI_Info *info) 
{
    int err;
    /*
     * Free all the alloced items from MPI_Info info.
     * Make sure the items are freed in an orderly
     * fashion so that there are no dangling pointers.
     */
    if (MPI_PARAM_CHECK) {
        OMPI_ERR_INIT_FINALIZE(FUNC_NAME);
        if (NULL == info || MPI_INFO_NULL == *info ||
            ompi_info_is_freed(*info)) {
            return OMPI_ERRHANDLER_INVOKE(MPI_COMM_WORLD, MPI_ERR_INFO,
                                          FUNC_NAME);
        }
    }

    err = ompi_info_free(info);
    OMPI_ERRHANDLER_RETURN(err, MPI_COMM_WORLD, err, FUNC_NAME);
}
