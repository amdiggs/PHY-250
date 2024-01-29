//
//  main.cpp
//  HelloCL
//
//  Created by Andrew Diggs on 1/27/24.
//

#include <iostream>


#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif


void Print_Device_Info(cl_device_id device_id){
    unsigned int info;
    size_t size;
    size_t sizes[3];
    char version[300];
    clGetDeviceInfo(device_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(info), &info, NULL);
    printf("GPU INFO: compute units = %u\n", info);
    
    
    clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: max work group size = %lu\n", size);
    
    
    clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(info), &info, NULL);
    printf("GPU INFO: work item demsions = %u\n", info);
    
    
    clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(sizes), sizes, NULL);
    printf("GPU INFO: work item sizes = %lux %lu x %lu\n", sizes[0], sizes[1], sizes[2]);
    
    
    clGetDeviceInfo(device_id, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: Global mem size = %lu MB\n", size/1000000);
    
    
    clGetDeviceInfo(device_id, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: Global mem cache size = %lu\n", size);
    
    
    clGetDeviceInfo(device_id, CL_DEVICE_LOCAL_MEM_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: local mem size = %lu B\n", size);
    
    
    clGetDeviceInfo(device_id, CL_DEVICE_IMAGE_MAX_ARRAY_SIZE, sizeof(size), &size, NULL);
    printf("GPU INFO: Max image array = %lu\n", size);
    
    clGetDeviceInfo(device_id, CL_DRIVER_VERSION, sizeof(version), &version, NULL);
    printf("GPU INFO: %s\n", version);
    
    clGetDeviceInfo(device_id, CL_DEVICE_OPENCL_C_VERSION, sizeof(version), &version, NULL);
    printf("GPU INFO: %s\n", version);
    
}


void GPU_INFO(){
    unsigned int err;
    cl_device_id device_id;
    err = clGetDeviceIDs(NULL,CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
    Print_Device_Info(device_id);
}


int main(int argc, const char * argv[]) {
    GPU_INFO();
    return 0;
}
