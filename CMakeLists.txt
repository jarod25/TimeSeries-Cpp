cmake_minimum_required(VERSION 4.0)
project(TimeSeries_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TimeSeries_Cpp
        main.cpp
        GaussianGenerator.cpp
        TimeSeriesGenerator.cpp
        StepGenerator.cpp
        SinWaveGenerator.cpp
        TimeSeriesDataset.cpp
        Distance.cpp
        KNN.cpp
)
