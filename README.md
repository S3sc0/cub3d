# cub3D

This is a school project inspired by the world-famous Wolfenstein 3D game where I created a playable environment with the help of ray-casting algorithm and a school made graphics library called MinilibX a simple X-Window (X11R6) programming API in C.

## ScreenShots

![](./screenshots/shot%20one.png)
![](./screenshots/shot%20two.png)
![](./screenshots/shot%20three.png)

## How To Use

This project is able to work in both linux machine and our school's mac only. If you have a linux machine follow these steps.
First you need to have MinilibX library follow [this](https://github.com/42Paris/minilibx-linux) guide to install it.
To get the project work properly in your machine run this script in your terminal.
```
>   ./configure.sh
``` 

Then compile the project.
```
>   make
```
You'll get an executable file called `cub3D` provided it with a map and that's it.
```
>   ./cub3D map.cub 
```

To take a screenshot provide the program with `--save` option.
```
>   ./cub3D map.cub --save
```

## How To Play
You can move around using you keyboard's arrows or using the following keys **W, A, S, D**.

## Configuration

There's a configuration file that allows you to manipulate the game environment called `map.cub` where you can:


- Change the window resolution, the unit is pixel.
```
    R 1000 700
```
- Change walls' texture, each face has a specific texture NO, SO, WE and EA meaning North, South, West and East respectively.
```
    NO ./textures/greystone.XPM
    SO ./textures/mossy.XPM
    WE ./textures/eagle.XPM
    EA ./textures/redbrick.XPM
``` 
- Change sprite which is an object that can be an obstacle and it's optional, notice that the file must be in XPM format.
```
    S ./textures/barrel.XPM
``` 
- Change the color of the ceil and the floor, the colors must be in RGB format.
```
    C 77,80,140
    F 242,80,65
```
- Change the game map as 2D map where 1 means a wall, 0 means an empty space, 2 means sprite object and N, S, W and E means a player and the direction he's facing.
```
            1111111111111111111111111
            1000000000110000000000001
            1011000001110000002000001
            1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000010001
    11110111111111011101010010001
    11000000110101011100000000001
    10002000000000001100000010001
    10000000000000001101010010001
    11000001110101011111011110N0111
    11110111 1110101 101111010001
    11111111 1111111 111111111111
```

## Resources

- [RayCasting part 1](https://lodev.org/cgtutor/raycasting.html)
- [RayCasting part 2](https://lodev.org/cgtutor/raycasting2.html)
- [RayCasting part 3](https://lodev.org/cgtutor/raycasting3.html)
- [RayCasting part 4](https://lodev.org/cgtutor/raycasting4.html)