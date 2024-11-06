#!/bin/bash

regions=('us' 'pal' 'jpn' 'us' 'pal')
versions=('v1' 'v1' 'v1' 'v2' 'v2')

for i in ${!regions[@]}; do
    region=${regions[$i]}
    version=${versions[$i]}
    echo "Compiling $region.$version"
    make REGION=$region VERSION=$version cleanextract && make REGION=$region VERSION=$version -j12
    if [[ $(sha1sum -c --quiet ver/verification/dkr.$region.$version.sha1) = "" ]]; then echo "$region.$version OK"; else echo "Failed $region.$version"; exit 1; fi
done
