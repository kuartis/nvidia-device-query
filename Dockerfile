# Copyright 2022 Kuartis.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

FROM nvidia/cuda:11.6.0-devel-ubuntu20.04 as builder
ADD main.cpp /main.cpp
RUN nvcc main.cpp -o app

FROM nvidia/cuda:11.6.0-base-ubuntu20.04
COPY --from=builder /app /app
CMD ["/app"]