from lib.googlenet import GoogLeNet
from lib.params import params
import lib.data_base as data_base
import datetime, gzip, pickle

def calc(Y):
    n = len(Y)
    m = tot;
    ret = [0] * n
    for i in range(0, n):
        max_rate = 0
        id = 0
        for j in range(0, m):
            if Y[i][j] > max_rate:
                max_rate = Y[i][j]
                id = j
        ret[i] = id
    return ret

args = params()                                     # set up params
training_set, testing_set = data_base.init(args.model_name, args.label_size, resize_pics = (args.img_size, args.img_size))  # set up data base
googlenet = GoogLeNet(args=args)                    # load GoogLeNet

tot = args.label_size;

tp = 0
fp = 0
fn = 0
tn = 0
tot_pkl = len(testing_set)
print("tot_pkl = %d" % tot_pkl)
for f in testing_set:
    X, Y = pickle.load(gzip.open(f, 'rb'))
    Y_ = googlenet.predict(X)
    answer = calc(Y);
    output = calc(Y_)

    n = len(Y)
    print("new test #: %d" % n)
    for i in range(0, n):
        if answer[i] == 1 and output[i] == 1:
            tp += 1
        if answer[i] == 1 and output[i] == 0:
            fn += 1
        if answer[i] == 0 and output[i] == 1:
            fp += 1
        if answer[i] == 0 and output[i] == 0:
            tn += 1
    print("precision = %.9f, recall = %.9f\n" % (float(tp) / float(tp + fp), float(tp) / float(tp + fn)))
    print("tp = %d, fn = %d, fp = %d, tn = %d\n" % (tp, fn, fp, tn))
print("precision = %.9f, recall = %.9f\n" % (float(tp) / float(tp + fp), float(tp) / float(tp + fn)))
print("tp = %d, fn = %d, fp = %d, tn = %d\n" % (tp, fn, fp, tn))
