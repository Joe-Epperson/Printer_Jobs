#include <iostream>
#include <random>
#include<time.h>
#include <vector>
using namespace std;

// Class to have an easy way to create a printing Job
class Job
{
private:
	int numPages;
	string jobSize;
	int printerUsed;

public:
	Job() { numPages = 0; jobSize = ""; printerUsed = 0; }
	void GetJob(int pageSize);
	// Functions to return the jobSize and numPages for use in sorting the jobs by size and for allocating the amount of time spent based on number of pages
	string GetJobSize() { return jobSize; }
	int GetNumPages() { return numPages; }
	void setPrinterUsed(int printerNum) { printerUsed = printerNum; }
	int getPrinterUsed() { return printerUsed; }
};

// Class which creates a printer for use, this class will keep track of the time it takes to print jobs as well as has a function to print jobs
class Printer
{
private:
	int totalTimeTaken;
	int printerNum;

public:
	Printer() { totalTimeTaken = 0; printerNum = 0; }
	// Function to reset the time so that the same printer variable can be used when testing for 1 2 or 3 printers
	void ResetTime() { totalTimeTaken = 0; }
	void SetPrinterNum(int printNum) { printerNum = printNum; }
	void PrintJob(vector<Job> &initialJobs, vector<Job>& finishedJobs);
	int GetTimeTaken() { return totalTimeTaken; }
};

// Function to get the job from the input and assign a size for easy interpretation later in the program
void Job::GetJob(int pageSize)
{
	numPages = pageSize;
	if (numPages < 10)
	{
		jobSize = "Small";
	}
	else if ((numPages >= 10) && (numPages < 20))
	{
		jobSize = "Medium";
	}
	else if ((numPages >= 20) && (numPages < 50))
	{
		jobSize = "Large";
	}
}

// Function to take the next job from the sorted jobs, complete that job, add the time taken to the totalTimeTaken variable, remove that job from the initialJobs vector and add it to the finishedJobs vector
void Printer::PrintJob(vector<Job>& initialJobs, vector<Job>& finishedJobs)
{
	int numPages = initialJobs.front().GetNumPages();
	initialJobs.front().setPrinterUsed(printerNum);
	int timeTaken = numPages * 6;
	totalTimeTaken += timeTaken;
	finishedJobs.push_back(initialJobs.front());
	initialJobs.erase(initialJobs.begin());
	
}

// Function to sort the 
void SortJobsBySize(vector<Job>& initialJobs)
{
	vector<Job> sortedJobs;
	int jobSize = initialJobs.size();

	// Searching through the jobs and taking only the small jobs and putting them into the sorted vector in order of when they were assigned
	for (int i = 0; i < jobSize; i++)
	{
		if ((initialJobs.at(i).GetJobSize()) == "Small")
		{
			sortedJobs.push_back(initialJobs.at(i));
		}
	}

	// Searching through the jobs and taking only the medium jobs and putting them into the sorted vector in order of when they were assigned
	for (int i = 0; i < jobSize; i++)
	{
		if ((initialJobs.at(i).GetJobSize()) == "Medium")
		{
			sortedJobs.push_back(initialJobs.at(i));
		}
	}

	// Searching through the jobs and taking only the large jobs and putting them into the sorted vector in order of when they were assigned
	for (int i = 0; i < jobSize; i++)
	{
		if ((initialJobs.at(i).GetJobSize()) == "Large")
		{
			sortedJobs.push_back(initialJobs.at(i));
		}
	}

	// initialJobs is passed by reference and therefore will be assigned with the sorted vector and keep those values for use outside of the function
	initialJobs = sortedJobs;
}

// Function to generate the output
void GenerateOutput(int timeTaken, vector<Job> unsortedJobs, vector<Job> finishedJobs, int numPrintersUsed)
{
	const int JobSize = unsortedJobs.size();

	int totalTime = timeTaken;
	int minutes = 0, seconds = 0, hours = 0;

	// Breaking the total print time(seconds) into hours, minutes, and seconds
	minutes = totalTime / 60;
	seconds = totalTime % 60;
	hours = minutes / 60;
	minutes -= (hours * 60);

	if (numPrintersUsed == 1)
	{
		// Outputting the jobs in relation to what order they were received
		cout << "Using one Printer" << endl << endl;
		cout << "The order in which the jobs were received: " << endl << endl;
		cout << "Job Number:     Number of Pages:     Job Size:" << endl;
		for (int i = 0; i < JobSize; i++)
		{
			cout << "     " << i+1 << "                 " << (unsortedJobs.at(i).GetNumPages()) << "             " << (unsortedJobs.at(i).GetJobSize()) << endl;
		}

		// Outputting the jobs in relation to what order they were completed
		cout << "The order in which the jobs were completed: " << endl << endl;
		cout << "Printer Number:     Number of Pages:     Job Size:" << endl;
		for (int i = 0; i < JobSize; i++)
		{
			cout << "       " << (finishedJobs.at(i).getPrinterUsed()) << "                  " << (finishedJobs.at(i).GetNumPages()) << "             " << (finishedJobs.at(i).GetJobSize()) << endl;
		}

		cout << "The total time used by the printer to do these jobs was: " << endl;
		cout << "Hours: " << hours << endl;
		cout << "Minutes: " << minutes << endl;
		cout << "Seconds: " << seconds << endl << endl << endl;
	}
	else if (numPrintersUsed == 2)
	{
		// Outputting the jobs in relation to what order they were received
		cout << "Using two Printers" << endl << endl;
		cout << "The order in which the jobs were received: " << endl << endl;
		cout << "Job Number:     Number of Pages:     Job Size:" << endl;
		for (int i = 0; i < JobSize; i++)
		{
			cout << "     " << i+1 << "                 " << (unsortedJobs.at(i).GetNumPages()) << "             " << (unsortedJobs.at(i).GetJobSize()) << endl;
		}

		// Outputting the jobs in relation to what order they were completed
		cout << "The order in which the jobs were completed: " << endl << endl;
		cout << "Printer Number:     Number of Pages:     Job Size:" << endl;
		for (int i = 0; i < JobSize; i++)
		{
			cout << "       " << (finishedJobs.at(i).getPrinterUsed()) << "                  " << (finishedJobs.at(i).GetNumPages()) << "             " << (finishedJobs.at(i).GetJobSize()) << endl;
		}

		cout << "The total time used by the printers to do these jobs was: " << endl;
		cout << "Hours: " << hours << endl;
		cout << "Minutes: " << minutes << endl;
		cout << "Seconds: " << seconds << endl;
	}
	else if (numPrintersUsed == 3)
	{
		// Outputting the jobs in relation to what order they were received
		cout << "Using three Printers" << endl << endl;
		cout << "The order in which the jobs were received: " << endl << endl;
		cout << "Job Number:     Number of Pages:     Job Size:" << endl;
		for (int i = 0; i < JobSize; i++)
		{
			cout << "     " << i+1 << "                 " << (unsortedJobs.at(i).GetNumPages()) << "             " << (unsortedJobs.at(i).GetJobSize()) << endl;
		}

		// Outputting the jobs in relation to what order they were completed
		cout << "The order in which the jobs were completed: " << endl << endl;
		cout << "Printer Number:     Number of Pages:     Job Size:" << endl;
		for (int i = 0; i < JobSize; i++)
		{
			cout << "       " << (finishedJobs.at(i).getPrinterUsed()) << "                  " << (finishedJobs.at(i).GetNumPages()) << "             " << (finishedJobs.at(i).GetJobSize()) << endl;
		}

		cout << "The total time used by the printers to do these jobs was: " << endl;
		cout << "Hours: " << hours << endl;
		cout << "Minutes: " << minutes << endl;
		cout << "Seconds: " << seconds << endl;
	}

}

int GetGreatest(int time1, int time2, int time3)
{
	if ((time1 > time2) && (time1 > time3))
	{
		return time1;
	}
	else if ((time2 > time1) && (time2 > time3))
	{
		return time2;
	}
	else if ((time3 > time1) && (time3 > time2))
	{
		return time3;
	}
}

int main()
{
	const int JobSize = 100;
	int randomPageNum;
	srand(time(NULL));

	Job tempJob;
	vector<Job> newJobs;
	vector<Job> unsortedOriginalJobs;
	vector<Job> completedJobs;

	// For loop to fill the newJobs vector with 100 jobs of a random page number between 1 and 50
	for (int i = 0; i < JobSize; i++)
	{
		randomPageNum = (rand() % 50) + 1;
		tempJob.GetJob(randomPageNum);
		newJobs.push_back(tempJob);
	}

	// Making a copy of the original vector so that we can output later the order in which the jobs were received
	unsortedOriginalJobs = newJobs;

	// Sorting the jobs in order of when they were received and the size of the job
	SortJobsBySize(newJobs);

	Printer printer1, printer2 , printer3;
	printer1.SetPrinterNum(1);
	printer2.SetPrinterNum(2);
	printer3.SetPrinterNum(3);
	int time1, time2, time3, totalTime;

	// Creating copies of the data so that the original data is useable in multiple trials
	vector<Job> tempNewJobs = newJobs;
	vector<Job> tempCompletedJobs = completedJobs;

	// Completing the jobs with one printer
	while (true)
	{
		if (tempNewJobs.size() > 0)
		{
			printer1.PrintJob(tempNewJobs, tempCompletedJobs);
		}
		else
		{
			break;
		}
	}
	time1 = printer1.GetTimeTaken();
	GenerateOutput(time1, unsortedOriginalJobs, tempCompletedJobs, 1);
	printer1.ResetTime();
	tempNewJobs = newJobs;
	tempCompletedJobs = completedJobs;

	// Completing the jobs with two printers
	while (true)
	{
		if (tempNewJobs.size() > 0)
		{
			printer1.PrintJob(tempNewJobs, tempCompletedJobs);
		}
		else
		{
			break;
		}
		if (tempNewJobs.size() > 0)
		{
			printer2.PrintJob(tempNewJobs, tempCompletedJobs);
		}
		else
		{
			break;
		}
	}
	time1 = printer1.GetTimeTaken();
	time2 = printer2.GetTimeTaken();
	totalTime = GetGreatest(time1, time2, 0);
	GenerateOutput(totalTime, unsortedOriginalJobs, tempCompletedJobs, 2);
	printer1.ResetTime();
	printer2.ResetTime();
	tempNewJobs = newJobs;
	tempCompletedJobs = completedJobs;

	// Completing the jobs with three printers
	while (true)
	{
		if (tempNewJobs.size() > 0)
		{
			printer1.PrintJob(tempNewJobs, tempCompletedJobs);
		}
		else
		{
			break;
		}
		if (tempNewJobs.size() > 0)
		{
			printer2.PrintJob(tempNewJobs, tempCompletedJobs);
		}
		else
		{
			break;
		}
		if (tempNewJobs.size() > 0)
		{
			printer3.PrintJob(tempNewJobs, tempCompletedJobs);
		}
		else
		{
			break;
		}
	}
	time1 = printer1.GetTimeTaken();
	time2 = printer2.GetTimeTaken();
	time3 = printer3.GetTimeTaken();
	totalTime = GetGreatest(time1, time2, time3);
	GenerateOutput(totalTime, unsortedOriginalJobs, tempCompletedJobs, 3);

	return 0;
}