1. Example Description
    This application demonstrates the usage of the DPGA Driver by amplifier voltage use Adc to read the voltage.
    the input voltage is 0.1V between Inp and Inm, the expected output voltage is 1.075V, 
    (DPGA_OUT = out_common_voltage + (input x gain) , out_common_voltage = 3.3V/12 , input = Inp-Inm = 0.1V , gain = 8).
    The application includes a S32DS project that configures the Mcu, Ae, Spi Platform and DPGA drivers.
    If all returned status and the measurement are correct, the bStatus variable remains "TRUE" until end of the example.

    1.1 The application software functionality
        - OsIf_Init Initialize timeout
        - Mcu_Init, Mcu_InitClock, Mcu_DistributePllClock, Mcu_SetMode
                Initialize the clock sources, the clock tree and to configure the clock gating of the peripherals.
                The clock configuration that is used will enable and use the PLL as source clock.
        - Initialize pins for LPSPI interface via the function Port_Init
        - Initialize configuration: baudrate, chip select,... of LPSPI through Spi_Init.
        - Initialize configuration's structure of AE through Ae_Init.
        - Active Dpga module in AE controller.
        - Dpga_Init
                Initialize the Dpga Driver
        - Ae_WriteRegister to write a value to register of AE block.
        - Ae_ReadRegister to read value for a register of AE block.
        - Dpga_DeInit
                Deinitializes the DPGA module.

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - XS32M2XXCVB-Q064 PCB 53099 RevX1 SCH RevA
            - Silicon : P32M276LC MKHS 0P73G CTZA2241B (E2)
        2.1.2 Connections
            - Inp(J132.4) connected to J108.1(adjust R201 to get 0.1V at J108.1)
            - Inm(J132.2) connected to J112.1(adjust R203 to get 0V at J112.1)
            - AMPOUT(J125.2) use multimeter to measure the output voltage, expected 1.075V
        2.1.3 Debugger
            - The debugger must be connected to J6 20-pin JTAG Cortex Debug connector on Motherboard.
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
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s).
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned below with the correct paths:
                    - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                        Ex: TRESOS_DIR = C:/EB/tresos_29
                    - GCC_DIR The path to the GCC installation dir
                        Ex: GCC_DIR = C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
                    - PLUGINS_DIR The path to the RTD plugins directory
                        Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
                2. Open the config.t32 file and update the path of SYS variable with the correct path:
                    - SYS The path to the T32 directory
                        Ex: SYS=C:/T32
3. Building the example application
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate sub-directory
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out sub-directory
    3.3 Running the application on the board
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
