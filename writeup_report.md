## Writeup Report

---

**PID Controller Project**

(Note - Hi , The visualization for the simulator on my machine is available at - https://youtu.be/UUwrmQ3Z-GM)

The goals / steps of this project are the following:

* Tune the PID controller hyperparameters.
* Test the result on the simulator. 
* Play around with the throttle.


## [Rubric](https://review.udacity.com/#!/rubrics/824/view) Points
### Here I will consider the rubric points individually and describe how I addressed each point in my implementation.  

---
### Writeup / README

#### 1. Provide a Writeup / README that includes all the rubric points and how you addressed each one.  You can submit your writeup as markdown or pdf.  [Here](https://github.com/udacity/CarND-Vehicle-Detection/blob/master/writeup_template.md) is a template writeup for this project you can use as a guide and a starting point.  

You're reading it!

### PID Controller

#### 1. Student describes the effect of the P, I, D component of the PID algorithm in their implementation.

The PID controller contains three components :

1. The proportional factor - obtained by multiplying the CTE Error (the deviation from the ideal trajectory) with the proportional gain (p*CTE)
2. The Differential factor - obtained by multiplying the CTE Error rate with the differential gain (d*E)
3. The Integral factor- obtained by multiplying the Steady state Error  with the Integral gain (i*S)

For the purpose of the project, I began by began with the values for p, d and i, as given in the PID implementation lesson of the classroom - 0.2 , 3.0 and 0.004 . Interestingly, these values in themselves produced quite a decent result.

To further tune the parameters, I initially thought of using twiddle, but once i actually opened the simulator i saw that there wasn't really a headless/manual mode where twiddle could tune the hyperparameter . Thus, I decided to manually adjust the values to iumprove the result. 

Now, as the environmental factors are mostly negligible i kept the integral gain very low, at around 0.003. The proportional gain I kept at 0.21 , almost equal to the value i took from the classroom. Lastly, I increased the differential gain by 30% to 0.39 as I could observe on testing out with slightly higher value of the differential gain than the classroom, that the jerkiness of the control especially at sharp turns . This I think is because the higher the derivative gain, more is the resistance towards changing the current trajectory too quick/suddenly, hence the decrease in jerkiness.I didn't increase it beyond the given value so as to avoid the system getting overdamped and taking too long to correct itself.

### Discussion

#### 1. Briefly discuss what could you do to make the implementation more robust?


The result has a room for improvement . There are a couple of hyperparameter tuning algorithms , which i'd like to try out (once i understand them better) to make the solution robust and make the control as smooth as possible. I feel that manual tuning is really not the best of the ways for implementation even though it is a bit intuitive.

