// Aidan Babb, 2/8/18, 9AM lab
// stats.cxx - implements statistician class as defined in stats.h
// YOUR NAME(S), DATE

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

namespace main_savitch_2C
{
    statistician::statistician(/*int inp_count, double inp_total, double inp_tiniest, double inp_largest*/){
        count = 0;
        total = 0;
        tiniest = 0;
        largest = 0;
    }

    void statistician::next(double r)
    {
        if (count == 0)
        {
            tiniest = r;
            largest = r;
        }

        count += 1;
        total += r;

        if (tiniest > r)
            tiniest = r;
        if (largest < r)
            largest = r;
    }

    void statistician::reset( )
    {
        count = 0;
        total = 0;
        tiniest = 0;
        largest = 0;
    }

    double statistician::mean( ) const
    {
        assert(count > 0);
        return (total / count);
    }

    double statistician::minimum( ) const
    {
        assert(count > 0);
        return tiniest;
    }
    double statistician::maximum( ) const
    {
        assert(count > 0);
        return largest;
    }

    statistician operator +(const statistician& s1, const statistician& s2)
    {
        statistician s3;
        s3.count = s1.count + s2.count;
        s3.total = s1.total + s2.total;
        if (s1.count == 0){
            s3.tiniest = s2.tiniest;
            s3.largest = s2.largest;
        }
        else if (s2.count == 0){
            s3.tiniest = s1.tiniest;
            s3.largest = s1.largest;
        }
        else{
            if (s1.tiniest < s2.tiniest)
                s3.tiniest = s1.tiniest;
            else
                s3.tiniest = s2.tiniest;
            if (s1.largest > s2.largest)
                s3.largest = s1.largest;
            else
                s3.largest = s2.largest;
        }
        return s3;
    }

    statistician operator *(double scale, const statistician& s)
    {
        statistician s2;
        s2.count = s.count;
        s2.total = s.total * scale;
        s2.tiniest = s.tiniest * scale;
        s2.largest = s.largest * scale;

        if (s2.tiniest > s2.largest)
        {
            int temp_tiny = s2.tiniest;
            s2.tiniest = s2.largest;
            s2.largest = temp_tiny;
        }
        return s2;
    }

    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if (s1.length() + s2.length() == 0)
            return true;
        if ((s1.length() == s2.length())&&(s1.maximum() == s2.maximum())&&(s1.minimum() == s2.minimum())&&(s1.sum() == s2.sum()))
            return true;
        else
            return false;
    }
}
