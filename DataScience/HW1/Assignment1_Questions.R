#Question 1
summary(College)
help(College)
attach(College)

# Question 2
ggplot(data=College)+geom_point(mapping=aes(x=Top10perc,y=Outstate),
  position="jitter")+geom_smooth(mapping=aes(x=Top10perc,y=Outstate))

# Question 3 a
ggplot(data=College)+
  geom_point(mapping=aes(x=Top10perc,y=Outstate, color = Private),
  position="jitter")+ 
  geom_smooth(mapping=aes(x=Top10perc,y=Outstate,group=Private))

# Question 3 b
ggplot(data=College)+
  geom_point(mapping=aes(x=Top10perc,y=Outstate),
             position="jitter")+ 
  geom_smooth(mapping=aes(x=Top10perc,y=Outstate,group=Private))+facet_wrap(~ Private, ncol = 2)



