from PIL import Image

# Open the image file
image_path = "1.jpg"  # Update with your image file path
image = Image.open(image_path)

# Convert the image to grayscale (if necessary)
image = image.convert("L")

# Convert the image to a 2D array
image_array = list(image.getdata())
width, height = image.size
image_2d_array = [image_array[i * width:(i + 1) * width] for i in range(height)]

# Check if all black pixels form a horizontal, vertical, or slant line
black_coordinates = []

for y, row in enumerate(image_2d_array):
    for x, pixel in enumerate(row):
        if pixel == 0:  # Black pixel
            black_coordinates.append((x, y))

# Determine if it's a horizontal, vertical, or slant line
if len(black_coordinates) > 1:
    x_coordinates, y_coordinates = zip(*black_coordinates)
    is_horizontal_line = len(set(y_coordinates)) == 1
    is_vertical_line = len(set(x_coordinates)) == 1
    is_slant_line = all(y - y_coordinates[0] == x - x_coordinates[0] for x, y in black_coordinates)
else:
    is_horizontal_line = is_vertical_line = is_slant_line = False

# Display the 2D array
for row in image_2d_array:
    print(row)

# Print the result
if is_horizontal_line and is_vertical_line and is_slant_line:
    print("The input image represents a single pixel.")
elif is_horizontal_line:
    print("The input image represents a horizontal line.")
elif is_vertical_line:
    print("The input image represents a vertical line.")
elif is_slant_line:
    print("The input image represents a slant line.")
else:
    print("The input image does not represent a straight line.")

