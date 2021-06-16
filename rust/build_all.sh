#!/bin/bash

cur_dir=$(pwd)
for path in * ;
do
    if [ -e ${path}/Cargo.toml ]; then
        # echo "${path}"
        cd ${cur_dir}/${path} && cargo build || exit 1 #
        cd ${cur_dir}
    fi
done

exit 0
