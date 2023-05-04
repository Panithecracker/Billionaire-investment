
%this script plots the probability of becoming a billionaire with respect
%to the proportion fixed at the start of the game.

%Also, it plots the expected/mean value for the final capital depending on
%the choice of the proportion f and other interesting data insights from
%the problem.

clear 
format long


x = linspace(0,1,1000);
for i = 1:size(x,2)
    y(i) = 100* ProbabilityBillionaire(x(i));
    z(i) = MinHeads(x(i));
    if (z(i) > 1000) %then, it is impossible to become a billionaire with this proportion
        z(i) = 0;
    end
%     mean(i) = Mean(x(i)); %store the mean of the final capital using this proportion
end
[X, Y] = meshgrid([0:1000],x);
for j = 1:size(X,1)
    for k = 1:size(X,2)
        Z(j,k) = log(FinalCapital(X(j,k),Y(j,k)));
    end
end
plot(x,y);
xlabel("Proportion");
ylabel("Chances of making more than a billion (%)");
% plot(x,loglog(mean));
figure 
plot(x,z);
xlabel("Proportion");
ylabel("Minimum # of heads to make > billion ");
figure
h = surf(X,Y,Z);
set(h,'LineStyle','none')
xlabel("#Heads");
ylabel("Proportion");
zlabel("FinalCapital");





function y = MinHeads(x) %computes the minimum n of heads for a given proportion
   y = ceil((9*log(10) -1000*log(1-x))/(log(1 +2*x) -log(1-x)));
end

function z = FinalCapital(h,f)  %rv that indicates the final capital given a number of heads (wins) and fixed proportion
     z = ((1-f)^1000)*((1+2*f)/(1-f))^h;
end

function y = ProbabilityBillionaire(x) %computes the probability of making more than a billion for a given proportion

   y = 1 - binocdf(MinHeads(x),1000,0.5);

end


% 
% function y = Mean(f) %computes the mean of the final capital for a fixed proportion f
%    %since the final capital is a discrete r.v transformed from the #heads
%    %rv (also discrete and binomial with params n = 1000 and p = 0.5) then:
%    y = 0;
%    for h = 1:1000 %weighted sum of final capitals for each #heads weighted by pmf of that # of heads
%        y = (FinalCapital(h,f)*binopdf(h,1000,0.5)) + y;
%    end
%  
% end
