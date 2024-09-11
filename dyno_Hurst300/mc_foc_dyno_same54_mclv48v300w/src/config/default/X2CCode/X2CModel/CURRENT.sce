VDD = 3.3;
SHUNT = 0.01;
GAIN = 4000/500;

Ipp = VDD/GAIN/SHUNT;

disp(Ipp)
