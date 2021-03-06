#include "stdafx.h"
#include "PiCalculator.h"
#include "SinglePiCalculator.h"
#include "MultiPiCalculator.h"

using namespace std;
using namespace std::chrono;

const int HELP_ARGC = 2;
const int WORK_ARGC = 3;
const int MIN_THREADS = 1;
const int MIN_ITERATIONS = 1;
const string HELP_FLAG = "--help";

void PrintHelp()
{
	printf("%s\n", "Usage: MonteCarloPi.exe <iterations> <threads>");
	printf("%7s%s\n", "", "MonteCarloPi.exe --help");
}

unique_ptr<PiCalculator> ChooseCalculator(size_t iterations, size_t threads)
{
	return (threads == MIN_THREADS)
		? (unique_ptr<PiCalculator>) make_unique<SinglePiCalculator>(iterations)
		: (unique_ptr<PiCalculator>) make_unique<MultiPiCalculator>(iterations, threads);
}

int main(int argc, char** argv)
{
	try
	{
		if (argc == WORK_ARGC)
		{
			int iterations = stoi(argv[1]);
			int threads = stoi(argv[2]);

			if (threads < MIN_THREADS)
			{
				throw invalid_argument("Count of threads must be positive");
			}
			if (iterations < MIN_ITERATIONS)
			{
				throw invalid_argument("Count of iterations must be positive");
			}

			unique_ptr<PiCalculator> calculator = ChooseCalculator(iterations, threads);
			time_point<high_resolution_clock> startTime = high_resolution_clock::now();
			double pi = calculator->Calculate();
			time_point<high_resolution_clock> endTime = high_resolution_clock::now();
			long long elipsed = duration_cast<milliseconds>(endTime - startTime).count();

			cout << "PI: " << pi << endl
				<< "Time: " << elipsed << " ms" << endl;
		}
		else if (argc == HELP_ARGC && argv[1] == HELP_FLAG)
		{
			PrintHelp();
		}
		else
		{
			PrintHelp();
			throw invalid_argument("Invalid argument count");
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
