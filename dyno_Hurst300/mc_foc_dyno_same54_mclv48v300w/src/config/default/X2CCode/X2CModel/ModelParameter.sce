// Simulation settings
endTime     = 5;
stepSize    = 1.0E-2;
X2C_sampleTime = 0.00005;


amplitude = 0.5;
offset = 0.0;
slength = 60;
r_up = 40;
r_up_fact = 0.0125;
r_down = 40;
r_down_fact = 0.0125;

t = -%pi : 2*%pi/256 : %pi

load_table1=t;//initilize as a row vector
load_table2=t;//initilize as a row vector
load_table3=t;//initilize as a row vector

// unbalanced load
load_table1 = amplitude*sin(t) + offset;
load_table1(257) = load_table1(1);

// broken bearing
load_table2(1)= offset;
for(i=2:256)
    if (i<=slength) then load_table2(i) = offset + amplitude
    else load_table2(i) = offset
    end  
end
load_table2(257) = load_table2(1);

// traingle load
load_table3(1)= offset;
for(i=2:256)
    if (i<=r_up) then load_table3(i) = offset + i*r_up_fact;
    elseif (i>r_up & i<(r_up+r_down)) then load_table3(i) = offset + r_up*r_up_fact - (i-r_up)*r_down_fact;
    else load_table3(i) = offset;
    end  
end
load_table3(257) = load_table3(1);

clf(10);
scf(10);figure(10)
plot(load_table1)
plot(load_table2)
plot(load_table3)
xtitle("load tables")




