'''This example is to demonstrate the scope and watch functionality side by side
Saving the values for the variable also in csv format for further analysis.
'''
import csv
import logging
import time

import matplotlib.pyplot as plt
#from utils import get_com_port, get_elf_file_path

from pyx2cscope.xc2scope import X2CScope

# Set up logging
logging.basicConfig(
    level=logging.INFO,
    filename=__file__ + ".log",
)

# X2C Scope Set up
elf_file = r"C:\Users\Brett\OneDrive\Desktop\Buewedge\ZSMT_dsPIC33CK_MCLV_48_300.X\dist\default\production\ZSMT_dsPIC33CK_MCLV_48_300.X.production.elf"
x2c_scope = X2CScope(port="COM7", elf_file=elf_file)

# Define variables
variables = [
    "motor.iabc.a",
    "motor.apiData.velocityReference",
    "motor.idq.q"
]

speed_reference = x2c_scope.get_variable("motor.apiData.velocityReference")
motorStaus = x2c_scope.get_variable("motor.apiData.motorStatus")
start_motor = x2c_scope.get_variable("systemData.board.sw1.buttonState")
for var in variables:
    x2c_scope.add_scope_channel(x2c_scope.get_variable(var))

# Set sample time to a higher number to get a bigger picture, losing resolution, default to 1
x2c_scope.set_sample_time(7)

# Create the plot
plt.ion()  # Turn on interactive mode
fig, ax = plt.subplots()


# Request scope to start sampling data


speed_reference.set_value(8000) # starting speed.#velocity reference
if motorStaus.get_value() == 1: #check for motor is running or not.
    start_motor.set_value(0) #button press if motor is stopped.
Speed_step = 500
value = speed_reference.get_value()

# Data Storage
csv_file_path = "data_pyx2cscope.csv"

x2c_scope.request_scope_data() # requesting for scope data.
# Open the CSV file in append mode
with open(csv_file_path, mode="w", newline="") as file:
    writer = csv.DictWriter(file, fieldnames=["Time (ms)"] + variables)
    writer.writeheader()

    while True:
        try:
            if x2c_scope.is_scope_data_ready():
                logging.info("Scope data is ready.")
                data_storage = {}
                for channel, data in x2c_scope.get_scope_channel_data(valid_data=False).items():
                    data_storage[channel] = data

                ax.clear()
                for channel, data in data_storage.items():
                    time_values = [i * 0.001 for i in range(len(data))]  # milliseconds rms = sqrt(mean(square(a)))
                    # time_values = [i * 0.000001 for i in range(len(data))]  # microseconds
                    ax.plot(time_values, data, label=f"Channel {channel}")

                ax.set_xlabel("Time (ms)")  # Change axis label accordingly
                ax.set_ylabel("Value")
                ax.set_title("Live Plot of Byte Data")
                ax.legend()

                plt.pause(0.001)  # Add a short pause to update the plot

                # Write data to CSV file incrementally
                max_length = max(len(data) for data in data_storage.values())
                for i in range(max_length):
                    row = {
                        "Time (ms)": i * 0.001,
                        **{channel: (data_storage[channel][i] if i < len(data_storage[channel]) else None) for channel in data_storage}
                    }
                    writer.writerow(row)

                x2c_scope.request_scope_data()
                value += Speed_step
                speed_reference.set_value(value)

        except Exception as e:
            logging.error(f"Error in main loop: {str(e)}")
            break

        time.sleep(0.1)

plt.ioff()  # Turn off interactive mode after the loop
plt.show()

logging.info("Data collection complete.")
logging.info(f"Data saved in {csv_file_path}")
