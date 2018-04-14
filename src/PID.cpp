#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
}

void PID::UpdateError(double cte) {
    double previous_cte = p_error;
    p_error = cte;
    i_error += cte;
    d_error = cte - previous_cte;
}

double PID::TotalError() {
    return Kp*p_error + Ki*i_error + Kd*d_error;
}

// Vector<double> twiddle(double tol, Vector<double> params){
//     //Don't forget to call `make_robot` before every call of `run`!
//     Vector<double> p = params;
//     Vector<double> dp = [1.0, 1.0, 1.0]
//     robot = make_robot()
//     x_trajectory, y_trajectory, best_err = run(robot, p)
//     # TODO: twiddle loop here
//     it = 0
//     while sum(dp) > tol:
//         print("Iteration {}, best error = {}".format(it, best_err))
//         for i in range(len(p)):
//             p[i] += dp[i]
//             robot = make_robot()
//             x_trajectory, y_trajectory, err = run(robot, p)

//             if err < best_err:
//                 best_err = err
//                 dp[i] *= 1.1
//             else:
//                 p[i] -= 2 * dp[i]
//                 robot = make_robot()
//                 x_trajectory, y_trajectory, err = run(robot, p)

//                 if err < best_err:
//                     best_err = err
//                     dp[i] *= 1.1
//                 else:
//                     p[i] += dp[i]
//                     dp[i] *= 0.9
//         it += 1
//     return p, best_err
// }