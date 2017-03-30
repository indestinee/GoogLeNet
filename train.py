from lib.googlenet import GoogLeNet
from lib.params import params
import lib.data_base as data_base
import datetime, gzip, pickle

fp = open("run.log", "w")                           # set up run log
args = params()                                     # set up params
training_set, testing_set = data_base.init(args.model_name, args.label_size, resize_pics = (args.img_size, args.img_size))
                                                    # set up data base
googlenet = GoogLeNet(args=args)                    # load GoogLeNet

begin = datetime.datetime.now()
fp.write("Start training:      --  %s\n" % str(begin))
while True:
    for data in training_set:
        X, Y = pickle.load(gzip.open(data, "rb"))
        googlenet.fit(X, Y, n_epoch = 20)
        print(" finish %s data_set.." % data) 
    now = datetime.datetime.now()
fp.write("Finished Training...  totle time = %s..       -- %s\n" % (str(now - begin), str(now)))
fp.close()
