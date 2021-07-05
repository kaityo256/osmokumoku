from PIL import Image
import numpy as np

im = np.array(Image.open("./robo.png"))
w, h, c = im.shape

im = im.reshape(w*h*c)

print("uint64_t array[] = {")
for i in range(im.size):
    print(f"{im[i]}",end="")
    if (i!=im.size-1):
        print(",",end="")
print("};")
