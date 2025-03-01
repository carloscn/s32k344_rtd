1. Example Description
    This application demonstrates the usage of a subset of Real Time Drivers that are included in this code drop. It is not part of the production code deliverables.
    The application includes an EB Tresos project that configures the Base, Dem, Dio, EcuC, Ocu, Mcl, Mcu, Os, Platform, Port and Resource drivers.
    The application uses the HLD layer functionality to trigger a compare match interrupt and blink LEDs on board.
    1.1 The application software functionality
            - Port_Init
                    Initialize the pins used by the application using the Port driver.
            - Mcu_init
                    Initialize the clock sources, the clock tree and to configure the clock gating of the peripherals.
                    The clock configuration that is used will enable and use the PLL as source clock.
            - Platform_Init
                    Initialize the interrupt controller and to apply the interrupt configuration according to the Platform configuration.
                    Install the ISR for the eMios timer used by the Ocu driver
            - Mcl_Init 
                    Initialize eMios counterBus use by Ocu.
            - Ocu_Init, Ocu_EnableNotification, Ocu_StartChannel
                    Initialize the Ocu driver, enable notification and start the selected channel.
            - After the initialization the channel will start counting, the notification will be generated upon each compare match and a 'while(1) loop' will run to blink a LED.
                    Notification function will toggle the PTB13 pin and will increase a 'count' variable by 1. 
                    The 'while(1) loop' will toggle the PTD0 gpio pin every 100 increments of the counter using Dio driver (Dio_WriteChannel).
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - Daughtercard: XS32K3X8CVB-Q289 PCB 53108 RevX3 SCH RevA1 
            - Motherboard: X-S32K3XXX-MB PCB 47386 RevA SCH RevA 
            - Silicon: P32K358GVS 0P14E CTZF2233B (E5) 
        2.2.2 Connections
            A wire connection is required between the following:
                - J183.4 (located on the motherboard) to J281.1 (located on the motherboard): PTD0(GPIO96) must be connected to D78 user LED.
                - J617 (located on motherboard) must be closed
        2.2.3 Debugger
            The Lauterbach debugger must be connected to J205 20-pin JTAG Cortex Debug connector located on the daughtercard.
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
                Ex: TRESOS_DIR = C:/EB/tresos_27.1
            - GCC_DIR The path to the GCC instalation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.3/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - PLUGINS_DIR The path to the Tresos plugins directory
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
