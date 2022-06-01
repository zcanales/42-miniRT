# 42-miniRT 📷 ⚡️
### Table of content
* [Description](#Description)
* [Usage](#Usage)
* [Compiling](#Compiling)
* [Render Examples](#Render-Examples)

## Description
This project is an introduction to the beautiful world of Raytracing.

The goal of this program is to generate images using the Raytracing protocol. Those computer-generated images will each represent a
scene, as seen from a specific angle and position, defined by simple geometric objects, and each with its own lighting system.
<p align="center">
<img src="https://github.com/zcanales/42-miniRT/blob/master/images/pinky_room.png?raw=true" width="400" height="400"></img>
</p>


MiniRT uses MinilibX, a simple graphics library that allows for simple window management and putting pixels to the screen.
The program can render spheres, planes and cylinders.


## Compiling
- Clone repository
``` 
git clone git@github.com:zcanales/42-miniRT.git
```
- Compile Madatory:
```
make
```
- Compile Bonus:
```
make bonus
```

## Usage
Run MiniRT with a .rt file as an argument. 
extension.
```
./miniRT [scene/*.rt]
``` 
The .rt file is a scene description file which must have the following information:
Each element first’s information is the type identifier (composed by one or two character(s)),
followed by all specific information for each object in a strict.
| ID  | x,y,z coordinates | Orientation | Intensity | Radius | Width | Height | Color | FOV |
|-|-|-|-|-|-|-|-|-|
|A| | |0.25| | | |255,255,255| |
|C|0,0,-10|0,0,1| | | | | | 65
|L|0,10,10| |0.75| | | |255,255,255 (Bonus)| |
|pl|0,0,0|0,1,0| | | | |129,22,255| |
|sp|0,1.25,0| | |2.5| | |129,22,90| |
|cy|1,2,-2|-0.2,0.3,1| ||3|10|129,255,90| |

## Render Examples
- Snowman.
<p align="center">
<img src="https://github.com/zcanales/42-miniRT/blob/master/images/snowman.png?raw=true" width="600" height="600"></img>
</p>

- 3 planes and 1 sphere.
<p align="center">
<img src="https://github.com/zcanales/42-miniRT/blob/master/images/3plans1.png?raw=true" width="600" height="600"></img>
</p>

 - Mickey Mouse shape.
<p align="center">
<img src="https://github.com/zcanales/42-miniRT/blob/master/images/mickey_mouse.png?raw=true" width="600" height="600"></img>
</p>
 - Random Scene.
 - <p align="center">
<img src="https://github.com/zcanales/42-miniRT/blob/master/images/scene_example.png?raw=true" width="600" height="600"></img>
</p>
