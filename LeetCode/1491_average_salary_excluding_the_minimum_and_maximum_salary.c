double average(int* salary, int salarySize)
{
    double min = 1e6;
    double max = 1000;
    int i = 0;
    double counter = 0;
    
    while (i < salarySize)
    {
        if (salary[i] < min)
            min = salary[i];
        if (salary[i] > max)
            max = salary[i];
        counter += salary[i];
        i++;
    }
    return((counter - (min + max))/(salarySize - 2));
}