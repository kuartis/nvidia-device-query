# NVIDIA Device Query

This is a simple container to query NVIDIA devices inside a container.

## Requirements
- CUDA capable GPU
- NVIDIA CUDA Runtime >= 11.6.0

## Usage

Docker:

```bash
docker run --privileged --gpus all ghcr.io/kuartis/nvidia-device-query:1.0.0
```

Kubernetes:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: nvidia-device-query
spec:
  containers:
    - name: nvidia-device-query
      image: ghcr.io/kuartis/nvidia-device-query:1.0.0
      resources:
        limits:
          nvidia.com/gpu: '1'
```

```bash
kubectl create -f pod.yaml
```
