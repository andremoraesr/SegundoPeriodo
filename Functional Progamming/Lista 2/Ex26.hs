altura :: Double -> Double -> Double
altura v0 t = v0*t - (10*t*t)/2


torricelli :: Double -> Double -> Double
torricelli v0 t = sqrt (v0 * v0 - 2*10*(-altura v0 t))
