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
Commande prototype : ./fractol <fractal-type> <prec:unsigned int>
<fractal-type> - julia:mandelbrot:mandelbrot2:mandelbrot3
<prec> - complexe sequence max iteration"
example
```
$ ./fractol julia 40
```

## Controls
MOVE : Key Arrows
FAST MOVE : Shift + Key Arrows
ZOOM : Mouse Scroll
ADD PRECISION : Press 'P'
LESS PRECISIONS : Press ':'
ON/OFF COLOR MENU : Press 'C'
ON/OFF SMOOTH : Press 'L'

<Inside the color menu>
Press 1 to select previous color
Press 2 to select next color
Press 3 to add a new color
HOLD the space bar to select the color inside the fractal
Move your mouse horizontally to change R value of the color
Move your mouse vertically to change G value of the color
Scroll your mouse up and down to change B value of the color

