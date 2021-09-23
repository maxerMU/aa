import os
import matplotlib.pyplot as plt

def plot_graphics(files):
    for i in range(len(files)):
        with open(files[i]) as f:
            plt.figure(i + 1)
            plt.title(files[i])

            x = []
            y = []
            for line in f:
                x_val, y_val = line.split(" ")
                x.append(x_val)
                y.append(y_val)
            ax = plt.gca()
            ax.set_xlabel("array size")
            ax.set_ylabel("ticks")
            plt.plot(x, y)
            plt.grid(True)

    plt.show()

if __name__ == "__main__":
    files = os.listdir(".")
    i = 0
    while i < len(files):
        if not files[i].endswith(".txt"):
            del(files[i])
        else:
            i += 1
    
    plot_graphics(files)
