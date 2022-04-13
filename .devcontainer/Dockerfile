ARG VARIANT="focal"

FROM ubuntu:${VARIANT}

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
	    software-properties-common wget apt-utils file zip \
		openssh-client gpg-agent socat rsync \
		make git python3 python3-pip

RUN python3 -m pip install --upgrade pip setuptools && \
	python3 -m pip install conan

ENV CONAN_SYSREQUIRES_SUDO 0
ENV CONAN_SYSREQUIRES_MODE enabled

# Install GCC for 11
RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
    apt-get update -qq && \
	apt-get install -y --no-install-recommends \
		gcc-11 g++-11 gdb

# Set gcc-11 as default gcc
RUN update-alternatives --install /usr/bin/gcc gcc $(which gcc-11) 100
RUN update-alternatives --install /usr/bin/g++ g++ $(which g++-11) 100

# Adding clang-LLVM
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - 2>/dev/null && \
	add-apt-repository -y "deb http://apt.llvm.org/focal/ llvm-toolchain-focal-13 main" && \
	apt-get update -qq && \
	apt-get install -y --no-install-recommends \
		clang-13 lldb-13 lld-13 clangd-13 \
		llvm-13-dev libclang-13-dev clang-tidy-13

# Set the default clang-tidy, so CMake can find it
RUN update-alternatives --install /usr/bin/clang-tidy clang-tidy $(which clang-tidy-13) 1

# Set clang-13 as default clang
RUN update-alternatives --install /usr/bin/clang clang $(which clang-13) 100
RUN update-alternatives --install /usr/bin/clang++ clang++ $(which clang++-13) 100

# Adding Cmake
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null \
		| gpg --dearmor - | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null && \
	apt-add-repository -y "deb https://apt.kitware.com/ubuntu/ focal main" && \
	apt-get update -qq && apt-get install -y --no-install-recommends cmake cmake-curses-gui

# Adding dependecies
RUN apt-get install -y --no-install-recommends \
		doxygen ccache cppcheck

# Cleanup all
RUN apt-get autoremove -y && apt-get clean && \
	rm -rf /var/lib/apt/lists/*

CMD ["/bin/bash"]