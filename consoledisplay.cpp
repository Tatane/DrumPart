#include "consoledisplay.h"

#include <iostream>

ConsoleDisplay::ConsoleDisplay()
{

}

void ConsoleDisplay::displayMeasure(const Measure &measure) const
{
    using MapLine = map<int, const Note*>; // key is the Placement
    map<int, unique_ptr<MapLine> > mapAllLine; // key is the Pitch, aka the id of the line.

    // Retrieving all notes of Measure :
    for(const Note* note : measure.getNotes())
    {
        if (note)
        {
            if (mapAllLine.count(note->getPitch()) == 0)
            {
                mapAllLine[note->getPitch()] = make_unique<MapLine>();
            }
            unique_ptr<MapLine> & mapLine = mapAllLine.at(note->getPitch());
            (*mapLine)[note->getPlacement()] = note;
        }
    }

    const int WIDTH_MEASURE = 16;

    int minLine = mapAllLine.begin()->first;
    int maxLine = mapAllLine.rbegin()->first;

    for(int line=maxLine; line>=minLine; --line)
    {
        if(mapAllLine.count(line) > 0)
        {
            MapLine * pLine = mapAllLine.at(line).get();
            for(int col=0; col<WIDTH_MEASURE; ++col)
            {
               if (pLine->count(col) > 0)
               {
                   if (line % 2)
                   {
                       cout<<"-X-";
                   }
                   else
                   {
                       cout<<" X ";
                   }
                   cout<<flush;
               }
               else
               {
                   if (line % 2)
                   {
                       cout<<"---";
                   }
                   else
                   {
                       cout<<"   ";
                   }

               }
            }

            cout<<endl;
        }
        else
        {
            for(int col=0; col<WIDTH_MEASURE; ++col)
            {
                if (line % 2)
                {
                    cout<<"---";
                }
            }
            cout<<endl;
        }
    }
}

