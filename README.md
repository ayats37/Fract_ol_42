# Fract-ol

## Description
This section gives an overview of the project. It introduces the concept of the project, stating that `fract-ol` allows users to generate and explore fractals like Mandelbrot, Julia, and Tricorn sets. It also highlights that the project was created as part of the 42 curriculum.

- **Mandelbrot**: Introduces the idea of visualizing the Mandelbrot set.
- **Julia**: Briefly introduces the Julia set and hints at the Tricorn fractal as a bonus feature.
- **Interactive Exploration**: Mention that the program allows interactive exploration through zooming and adjusting parameters.

## Features
Here, we list the key features of the project:
- **Fractal Generation**: Describes the Mandelbrot and Julia sets and the bonus Tricorn fractal.
- **Zooming and Panning**: Allows the user to interactively zoom in and out and pan around the fractals.
- **Real-Time Rendering**: Ensures that the fractals are rendered dynamically as users interact with them.
- **Customizable Color Palettes**: Users can adjust the colors of the fractals to suit their preferences.
- **Performance Optimized**: Focuses on efficient rendering and smooth interaction.

## Installation
This section explains the installation process to get the project up and running locally:
- **Clone the Repository**: Instructions on how to clone the GitHub repository.
- **Navigate to the Directory**: Once the project is cloned, users should navigate to the project folder.
- **Compile the Project**: The instructions tell users to use `make` to compile the project and prepare it for execution.
- **Run the Application**: Finally, users can execute the program by running the generated binary (`./fractol`).

## Usage
This section explains how to use the application once it is running:
- **Zoom and Pan**: Describes how to zoom in and out using the mouse and how to pan the fractal by clicking and dragging.
- **Switch Fractals**: Allows the user to switch between the different fractals using keyboard inputs.
- **Adjust Parameters**: Users can modify the fractal's visual parameters like color, zoom level, and iteration depth using the keyboard.

## Visual Examples

### Mandelbrot Set
This section gives a visual representation of the **Mandelbrot set**, one of the most well-known fractals. The Mandelbrot set is defined by the function `f(z) = z^2 + c`, and the section explains that it consists of all the points `c` where the function does not escape to infinity. An image of the Mandelbrot set is included to show what it looks like.

![Mandelbrot Set](https://upload.wikimedia.org/wikipedia/commons/a/a5/Mandelbrot_set.png)

### Julia Set
The **Julia set** is similar to the Mandelbrot set but involves iterating the function `f(z) = z^2 + c` with a fixed `c` value. The section explains the difference between Mandelbrot and Julia sets. An image of a Julia set is also provided to visualize it.

![Julia Set](https://upload.wikimedia.org/wikipedia/commons/2/24/Julia_set_%28high_quality%29.png)

### Tricorn Fractal (Bonus)
The **Tricorn fractal** is introduced as a bonus feature. It is similar to the Julia set but iterates the function with the conjugate of `z`, which results in a mirror-symmetric pattern. This section includes a visual representation of the Tricorn fractal.

![Tricorn Fractal](https://upload.wikimedia.org/wikipedia/commons/2/25/Tricorn_fractal.png)

## Bonus: Tricorn Fractal
The **Tricorn fractal** is a bonus fractal in the project. It uses the conjugate of `z` during iteration instead of the original `z`, which results in a visually different and interesting pattern. Users can switch to the Tricorn fractal by pressing the **T** key, similar to switching between other fractals like Mandelbrot and Julia.

### How to Use the Tricorn Fractal
Instructions for how to switch to the Tricorn fractal:
- Press **T** to switch to the Tricorn fractal.
- Other controls for zooming and parameter adjustments remain the same.

## Troubleshooting
This section provides troubleshooting tips for users who might encounter issues during installation or usage. It also offers solutions to common problems like compilation errors. Users are advised to run the following commands to clean and rebuild the project if needed:
```bash
make clean
make
