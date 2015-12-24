# BlackAdder
Additive synthesizer audio unit

This supercedes my [Plus](https://github.com/wbajzek/Plus) project. 
I am starting over from the ground up with more experience and a better plan.
Plus was sort of haphazardly thrown together and committed to git in an 
undisciplined fashion; I intend to iterate on BlackAdder more thoughtfully
with the goal of producing a stable, performant, professional-quality product
which will remain free and open source. 

In my previous attempt I failed to achieve acceptable performance for the 
number of simultaneous oscillators and envelopes that I had added. I also found
the interface too time-consuming to use, having individual settings for every
partial.

So, for this rewrite, I am simplifying the design so there are 4 envelopes,
selectable per partial, rather than one for each partial. For 8 voices, this means
36 total envelopes to calculate, not 256. I still want 32 partials per voice,
which means a total of 256 oscillators, but in my previous attempt, the envelopes
seemed to be a bigger bottleneck than the oscillators.

Also, since performance was such a killer of an issue before, I am beginning this
project by making a dumb plugin which has 256 oscillators and 36 envelopes going
simultaneously, so I can focus on achieving viable performance before sinking too
much time into feature development.

I have a [Trello board](https://trello.com/b/HUgnYxis/additive-synthesizer) for
this project if you would like to track my progress and/or contribute.
