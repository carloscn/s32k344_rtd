1. Example Description
    This application demonstrates the usage of a subset of Real Time Drivers that are included in this code drop. It is not part of the production code deliverables.
    The application includes an EB Tresos project that configures the Base, Dem, Dio, EcuC, Gpt, Mcu, Platform, Port and Resource drivers.
    1.1 The application software functionality
            - Port_Init
                    Initialize the pins used by the application using the Port driver.
            - Mcu_Init, Mcu_InitClock, Mcu_SetMode
                    Initialize the clock sources, the clock tree and to configure the clock gating of the peripherals.
            - Platform_Init
                    Initialize the interrupt controller and to apply the interrupt configuration according to the Platform configuration.
            - Platform_InstallIrqHandler
                    Install the ISR for the PIT timer used by the Gpt driver
            - Gpt_Init, Gpt_StartTimer, Gpt_EnableNotification
                    Initialize the Gpt driver, start the selected channel and enable its notification.
            - After the initialization the channel will start counting, the notification will be generated and a 'while(1) loop' will run to blink a LED.
                    The 'while(1) loop' will toggle the PTH7 gpio pin after each event generated by the notification using Dio driver (Dio_WriteChannel).

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - Daughter Board: XS32K396-BGA-DC PCB 54614 RevX1 SCH RevA
            - Silicon: E5 sample, 289MBGA: P32K396EHMJBS OP40E QAD2222F 
        2.1.2 Connections
            A wire connection is required: N/A, PTH7 is controlling the BLUE LED (D35)
        2.2.3 Debugger
            The debugger must be connected to J20 20-Pin ARM Standard JTAG Connector.
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed in the Tresos Studio plugins directory
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder
                    e. Optional* - Select "Copy projects into workspace" 
                    f. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos/29.0.0
            - GCC_DIR The path to the GCC installation directory
                Ex: GCC_DIR = C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins 
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate subdirectory
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.3 Running the application on the board
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
