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
![Julia Fractal](screenshots/Capture%20d'écran%202022-01-07%20à%2000.35.23.png)
![Julia Fractal with Colors](screenshots/Capture%20d'écran%202022-01-07%20à%2000.36.54.png)

### Mandelbrot Sets  
![Mandelbrot Fractal](screenshots/Capture%20d'écran%202022-01-07%20à%2000.37.24.png)
![Mandelbrot with Different Colors](screenshots/Capture%20d'écran%202022-01-07%20à%2000.38.11.png)

### Color Variations
![Colorful Fractal 1](screenshots/Capture%20d'écran%202022-01-08%20à%2021.40.02.png)
![Colorful Fractal 2](screenshots/Capture%20d'écran%202022-01-08%20à%2021.45.10.png)

### High Precision Renders
![High Detail Fractal 1](screenshots/Capture%20d'écran%202022-01-15%20à%2021.16.27.png)
![High Detail Fractal 2](screenshots/Capture%20d'écran%202022-01-15%20à%2021.30.43.png)

### Zoom Effects
![Zoomed Fractal 1](screenshots/Capture%20d'écran%202022-01-15%20à%2023.09.24.png)
![Zoomed Fractal 2](screenshots/Capture%20d'écran%202022-01-16%20à%2002.12.18.png)

