#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	cp ./os/header_linux ./cub3d.h
	cp ./os/Makefile_linux ./Makefile
elif [[ "$OSTYPE" == "darwin"* ]]; then
	cp ./os/header_mac ./cub3d.h
	cp ./os/Makefile_mac ./Makefile
fi

echo "Use These Commands Now: "
echo ">> make"
echo ">> ./cub3D map.cub"