
%this script plots the probability of becoming a billionaire with respect
%to the proportion fixed at the start of the game.
clear 
format long



x = linspace(0,1,8000);
for i = 1:size(x,2)
    y(i) = 100* ProbabilityBillionaire(x(i));
    z(i) = MinHeads(x(i));
    if (z(i) > 1000) %then, it is impossible to become a billionaire with this proportion
        z(i) = 0;
    end
end
plot(x,y);
xlabel("Proportion");
ylabel("Chances of making more than a billion (%)");
figure 
plot(x,z);


function y = MinHeads(x) %computes the minimum n of heads for a given proportion
   y = ceil((9*log(10) -1000*log(1-x))/(log(1 +2*x) -log(1-x)));
end

function y = ProbabilityBillionaire(x) %computes the probability of making more than a billion for a given proportion

   y = 1 - binocdf(MinHeads(x),1000,0.5);

end