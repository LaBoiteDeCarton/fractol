# Fractol - Fractal rendering with mlx
***
## Installation
```
$ git clone https://github.com/LaBoiteDeCarton/fractol.git
$ cd /fractol
$ make
```
***
## Usage
Commande prototype : ./fractol fractalname precision  
fractalname : julia / mandelbrot / mandelbrot2 / mandelbrot3  
precision *unsigned int*: maximum iteration for the complexe sequence  
example  
```
$ ./fractol julia 40
```
***
## Controls
__Basics__   
MOVE : Key Arrows  
FAST MOVE : Shift + Key Arrows  
ZOOM : Mouse Scroll  
ADD PRECISION : Press 'P'  
LESS PRECISIONS : Press ':'  
CHANGE COLORS : Press Tab  
ON/OFF COLOR MENU : Press 'C'  
ON/OFF SMOOTH : Press 'L'  
FIXE THE COMPLEXE VALUE : *only for Julia fractal* Mouse Left Click
***
__Inside the color menu__  
Press 1 to select previous color  
Press 2 to select next color  
Press 3 to add a new color  
HOLD the space bar to select the color inside the fractal  
Move your mouse horizontally to change R value of the color  
Move your mouse vertically to change G value of the color  
Scroll your mouse up and down to change B value of the color  

***
## Screenshots

Here are some examples of the beautiful fractals you can generate with this program:

### Julia Sets
![Julia Fractal](screenshots/FractalJulia.png)
![Julia Fractal Blue](screenshots/FractalJuliaBlue.png)
![Julia Fractal Red](screenshots/FractalJuliaRed.png)

### Julia Set Variations  
![Julia Blue-Green](screenshots/FractalJuliaBlueGreen.png)
![Julia Light Blue](screenshots/FractalJuliaLightBlue.png)
![Julia Thunder](screenshots/FractalJuliaThunder.png)

### Julia Color Mix
![Julia Mix 1](screenshots/FractalJuliaMix.png)
![Julia Mix 2](screenshots/FractalJuliaMix2.png)
![Julia Mix 3](screenshots/FractalJuliaMix3.png)

### Zoom Effects - Julia
![Julia Zoom](screenshots/FractalJuliaZoom.png)
![Julia Zoom Blue](screenshots/FractalJuliaZoomBlue.png)

### Mandelbrot Zoom Series
![Mandelbrot Zoom 1](screenshots/FractalMandelbrotZoom.png)
![Mandelbrot Zoom 2](screenshots/FractalMandelbrotZoom2.png)
![Mandelbrot Zoom 3](screenshots/FractalMandelbrotZoom3.png)
![Mandelbrot Zoom 4](screenshots/FractalMandelbrotZoom4.png)
![Mandelbrot Zoom 5](screenshots/FractalMandelbrotZoom5.png)
![Mandelbrot Zoom 6](screenshots/FractalMandelbrotZoom6.png)
