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

extern const mca_base_component_t mca_llm_hostfile_component;

const mca_base_component_t *mca_llm_base_static_components[] = {
  &mca_llm_hostfile_component, 
  NULL
};
