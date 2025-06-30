# Mountain Car
[code](./mountain_car.py)

Training for 5000 episodes gave a good model.<br>
But despite increasing number of episodes from 5000 to 20000, produced a bad model.

Trained with <br>
g : 0.9<br>
lr : 0.9<br>
## With np seed 0
### During training
|(5k) Failure %|(5k) Avg reward|(20k) Failure %|(20k)Avg reward|
|---|---|---|---|
|63.72|-181.2134|63.715|-187.05025|

For 5000 episodes

![](MountainCar-v0_5000_np_0_d_0.0004_g_0.9_lr_0.9.jpg "Mountain Car")

For 20000 episodes

![](MountainCar-v0_20000_np_0_d_0.0001_g_0.9_lr_0.9.jpg "Mountain Car")

#### During testing
|Seed|(5k) Failure %|(5k) Avg reward|(20k) Failure %|(20k)Avg reward|
|---|---|---|---|---|
|0|0.0| -147.865|10.0|-168.907|
|1|0.0| -148.537|6.6 |-168.040|
|2|0.0| -148.597|6.5 |-167.974|
|3|0.0| -147.695|7.2 |-167.804|
|4|0.0| -148.495|7.8 |-168.508|
|5|0.0| -148.393|8.5 |-168.598|
|6|0.0| -148.275|8.3 |-168.513|
|7|0.0| -148.839|6.2 |-167.895|
|8|0.0| -148.296|7.2 |-168.007|
|9|0.0| -148.347|7.9 |-168.463|

For 5000 episodes

![](MountainCar-v0_testing_5000.jpg "Mountain Car")

For 20000 episodes

![](MountainCar-v0_testing_20000.jpg "Mountain Car")


## With np seed 42
#### During training
|(5k) Failure %|(5k) Avg reward|(20k) Failure %|(20k)Avg reward|
|---|---|---|---|
|71.06|-191.9536|65.285|-184.94605|

For 5000 episodes

![](MountainCar-v0_5000_np_42_d_0.0004_g_0.9_lr_0.9.jpg "Mountain Car")

For 20000 episodes

![](MountainCar-v0_20000_np_42_d_0.0001_g_0.9_lr_0.9.jpg "Mountain Car")

#### During testing
|Seed|(5k) Failure %|(5k) Avg reward|(20k) Failure %|(20k)Avg reward|
|---|---|---|---|---|
|0|26.9| -188.272|35.9| -172.224|
|1|26.3| -187.883|31.6| -169.344|
|2|23.4| -187.730|32.5| -169.032|
|3|29.0| -188.712|35.5| -172.080|
|4|25.7| -187.437|32.0| -169.347|
|5|24.4| -187.865|36.1| -170.791|
|6|25.2| -188.523|34.8| -170.930|
|7|25.4| -187.128|30.6| -168.272|
|8|24.4| -187.451|34.3| -170.648|
|9|24.4| -187.670|33.2| -170.322|

For 5000 episodes

![](MountainCar-v0_testing_5000_42.jpg "Mountain Car")

For 20000 episodes

![](MountainCar-v0_testing_20000_42.jpg "Mountain Car")

## Similarly for seed 2
During training 

|(5k) Failure %|(5k) Avg reward|(20k) Failure %|(20k)Avg reward|
|---|---|---|---|
|73.36|-191.9178|63.945|-185.4021|

During testing

|Seed|(5k) Failure %|(5k) Avg reward|(20k) Failure %|(20k)Avg reward|
|---|---|---|---|---|
|0|0.0| -162.518|22.0| -158.825|
|1|0.0| -162.571|23.5| -159.887|
|2|0.0| -162.512|21.2| -158.827|
|3|0.0| -162.503|22.7| -159.159|
|4|0.0| -162.510|24.2| -160.284|
|5|0.0| -162.431|24.0| -160.091|
|6|0.0| -162.475|25.4| -160.716|
|7|0.0| -162.511|22.3| -159.444|
|8|0.0| -162.463|23.5| -159.820|
|9|0.0| -162.490|23.5| -159.841|

