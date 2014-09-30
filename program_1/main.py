# Python Implementation

def dat_fun():
    with open("Human_MtDNA.txt", "r") as ifile:
        for line in ifile:
            if not line:
                break
            yield line