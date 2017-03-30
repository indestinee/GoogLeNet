import os
from lib import data_utils
def init(dirname, label_size, resize_pics=(224, 224), down_sampling=None):
    pkl_fnames = ["images/%s/%s" % (dirname, f) for f in os.listdir("images/%s/" % dirname) if "samples_" in f]
    if not pkl_fnames:
        pkl_fnames = data_utils.image_dirs_to_samples(dirname, label_size,
            resize=resize_pics, convert_gray=False, filetypes=['.jpg', '.jpeg', 'png'], 
            down_sampling=down_sampling, categorical_Y=True, shuffle_data=True)
    training_totle = 0.6;

    n = len(pkl_fnames)
    m = int(n * training_totle)
    training_set = []
    testing_set = []
    for i in range (0, m):
        training_set.append(pkl_fnames[i])
    for i in range (m, n):
        testing_set.append(pkl_fnames[i])
    return training_set, testing_set


