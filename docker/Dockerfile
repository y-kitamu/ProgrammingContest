FROM ubuntu:latest

ENV DEBIAN_FRONTEND noninteractive

# ssh (https://docs.docker.com/engine/examples/running_ssh_service/)
RUN apt-get update && apt-get upgrade -y && apt-get install openssh-server -y
RUN mkdir /var/run/sshd
RUN sed -ri 's/^#?PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config

# gcc
RUN apt-get update &&\
    apt-get upgrade -y &&\
    apt-get install -y sudo build-essential git ninja-build openssl libssl-dev software-properties-common
RUN apt-get install gcc-12 g++-12 -y

# build cmake
WORKDIR / opt
RUN git clone https://github.com/Kitware/CMake.git cmake &&\
    cd cmake &&\
    ./bootstrap &&\
    make && make install
WORKDIR /

# clang
WORKDIR /opt
ARG LLVM_VERSION=16
RUN wget https://apt.llvm.org/llvm.sh &&\
    chmod +x llvm.sh &&\
    ./llvm.sh ${LLVM_VERSION}
WORKDIR /

# c++ (ccls)
WORKDIR /opt
RUN apt-get install -y libllvm-${LLVM_VERSION}-ocaml-dev llvm-${LLVM_VERSION}-doc llvm-${LLVM_VERSION}-examples
RUN apt-get install -y  \
    clang-tools-${LLVM_VERSION}\
    clang-${LLVM_VERSION}-doc \
    libclang-${LLVM_VERSION}-dev\
    clang-format-${LLVM_VERSION}\
    python3-clang-${LLVM_VERSION}\
    libstdc++-11-dev
RUN git clone --depth=1 --recursive https://github.com/MaskRay/ccls && cd ccls &&\
    cmake -H. -BRelease -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_PREFIX_PATH=/usr/lib/llvm-${LLVM_VERSION}/ &&\
    cmake --build Release && ln -s /opt/ccls/Release/ccls /usr/local/bin/
WORKDIR /

# add user
ARG uid
ARG gid
ARG user
RUN groupadd --gid ${gid} ${user} && useradd -ms /bin/bash --uid ${uid} --gid ${gid} ${user}
RUN usermod -aG sudo ${user}

# link clang
RUN ln -s /usr/bin/clang-${LLVM_VERSION} /usr/bin/clang && ln -s /usr/bin/clang++-${LLVM_VERSION} /usr/bin/clang++

# copy latest ninja
RUN apt-get install -y unzip
ADD https://github.com/ninja-build/ninja/releases/download/v1.11.1/ninja-linux.zip /opt
RUN rm /usr/bin/ninja && unzip /opt/ninja-linux.zip -d /usr/bin && rm /opt/ninja-linux.zip
