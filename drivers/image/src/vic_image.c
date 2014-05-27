#include <vic_def.h>
#include <vic_run.h>
#include <vic_driver_image.h>

char               *version = "VIC 5.0 image";

int                 NF, NR;
size_t              current;
all_vars_struct    *all_vars = NULL;
atmos_data_struct  *atmos = NULL;
dmy_struct         *dmy = NULL;
filenames_struct    filenames;
filep_struct        filep;
global_param_struct global_param;
option_struct       options;
param_set_struct    param_set;
domain_struct       global_domain;
soil_con_struct    *soil_con = NULL;
veg_con_map_struct *veg_con_map = NULL;
veg_con_struct    **veg_con = NULL;
veg_lib_struct    **veg_lib = NULL;

int
main(int    argc,
     char **argv)
{
    size_t i;
    
    cmd_proc(argc, argv, filenames.global);

    vic_start();
    vic_alloc();
    vic_init();
    vic_force();
    vic_restore();
    for (current = 0;  current < global_param.nrecs; current++) {
        vic_force();
        for (i = 0; i < global_domain.ncells_global; i++) {
            // vic_run()
        }
        // if output:
        // vic_write()
        // if save:
        // vic_save()
    }
    vic_finalize();

    return EXIT_SUCCESS;
}
