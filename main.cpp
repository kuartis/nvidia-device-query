// Copyright 2022 Kuartis.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdio.h>
#include <cuda_runtime.h>

// Print device properties
void printDevProp(cudaDeviceProp devProp)
{
  printf("Major revision number:         %d\n", devProp.major);
  printf("Minor revision number:         %d\n", devProp.minor);
  printf("Name:                          %s\n", devProp.name);
  printf("Total global memory:           %u\n", devProp.totalGlobalMem);
  printf("Total shared memory per block: %u\n", devProp.sharedMemPerBlock);
  printf("Total registers per block:     %d\n", devProp.regsPerBlock);
  printf("Warp size:                     %d\n", devProp.warpSize);
  printf("Maximum memory pitch:          %u\n", devProp.memPitch);
  printf("Maximum threads per block:     %d\n", devProp.maxThreadsPerBlock);
  for (int i = 0; i < 3; ++i)
    printf("Maximum dimension %d of block:  %d\n", i, devProp.maxThreadsDim[i]);
  for (int i = 0; i < 3; ++i)
    printf("Maximum dimension %d of grid:   %d\n", i, devProp.maxGridSize[i]);
  printf("Clock rate:                    %d\n", devProp.clockRate);
  printf("Total constant memory:         %u\n", devProp.totalConstMem);
  printf("Texture alignment:             %u\n", devProp.textureAlignment);
  printf("Concurrent copy and execution: %s\n", (devProp.deviceOverlap ? "Yes" : "No"));
  printf("Number of multiprocessors:     %d\n", devProp.multiProcessorCount);
  printf("Kernel execution timeout:      %s\n", (devProp.kernelExecTimeoutEnabled ? "Yes" : "No"));
  return;
}

int main()
{
  // Number of CUDA devices
  int devCount;
  cudaGetDeviceCount(&devCount);
  printf("CUDA Device Query...\n");
  printf("There are %d CUDA devices.\n", devCount);

  // Iterate through devices
  for (int i = 0; i < devCount; ++i)
  {
    // Get device properties
    printf("\nCUDA Device #%d\n", i);
    cudaDeviceProp devProp;
    cudaGetDeviceProperties(&devProp, i);
    printDevProp(devProp);
  }
  return 0;
}