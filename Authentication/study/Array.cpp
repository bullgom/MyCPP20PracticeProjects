#include <iostream>
#include <vector>
#include <random>
#include <ranges>
#include <algorithm>
#include <chrono>
#include <functional>

/*
 * Array is a `type`
 * consisting of a contiguously allocated 
 * nonempty sequence of objects
 * with a particular element type
 * 
 * Number of those objects (the array size) never changes during the array life time
 */

namespace ranges = std::ranges;

struct Model
{
    double next_event_time;
};

std::vector<Model> generate_examples(int number)
{
    // A uniform random number generator object
    // Used as the source of randomness
    std::default_random_engine generator;

    // Calls () operator on generator to get uniformly-distributed integers
    // then transforms the obtained values to output the disired distribution

    // Will uniformly generate values between 0 ~ 1
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    std::vector<Model> models;

    for (auto i = 0; i < number; i++)
    {
        models.push_back(Model{.next_event_time = distribution(generator)});
    }

    return models;
}

Model get_next_model(std::vector<Model> &models)
{
    /*
     * sort modifys the vector
     * So you can't be declaring parameter as const
     */

    ranges::sort(models, ranges::less{}, [](const Model &x) { return x.next_event_time; });

    return models[0];
}

Model get_next_model2(std::vector<Model> &models)
{
    return ranges::min(models, ranges::less{}, [](const Model &x) { return x.next_event_time; });
    
}

double timeit(int repeats, int items, std::function<void(int)> func)
{
    auto begin = std::chrono::steady_clock::now();
    for (auto i = 0; i < repeats; i++)
        func(items);
    auto end = std::chrono::steady_clock::now();
    auto dur = (end - begin);

    auto total_time = std::chrono::duration_cast<std::chrono::microseconds>(dur);

    return total_time.count() / repeats;
}

void timeOne(int items)
{
    std::vector<Model> models = generate_examples(items);

    get_next_model(models);
}

void timeTwo(int items)
{
    auto models = generate_examples(items);
    get_next_model2(models);
}

int main()
{
    /*
     * I think you'll do yourself a favor if you forget about optimization and just  
     * write readable code 
     * (you'll need to run a profiler later - but don't pre-optimize).
     */

    int items = 1000;
    int repeats = 10000;
    double t1 = timeit(repeats, items, timeOne);

    std::cout << t1 << "[ms]"<< std::endl;

    std::cout << timeit(repeats, items, timeTwo) << "[ms]" << std::endl;

    return 0;
}
