1. Example Description
    This application demonstrates the usage of the Platform for configuring MPU.
    This example will configure for MPU module, create 5 MPU region based on Linker file.
    Change access permission for MPU_SHAREABLE region and try to write access to check whether enter MemManageFault or not.
    The application includes an EB Tresos project that configures the Mcu, Mcl, and Platform drivers.
    1.1 The application software functionality
            - Mcu_Init, Mcu_InitClock, Mcu_DistributePllClock, Mcu_SetMode
                    Initialize the clock sources, clock tree and configure the clock gating of the peripherals.
                    Apply a mode configuration for MCU.
            - Mcl_CacheClean
                    Cleaning cache by calling Mcl_CacheClean() function to ensure data is correct before disabling cache
            - Mcl_CacheDisable
                    Disable cache by calling Mcl_CacheDisable() function to Turn off cache to ensure data is written in RAM
            - Platform_Init
                    Initialize the interrupt controller and apply the interrupt configuration according to the Platform configuration.
                    Configuring 5 MPU regions with the following attributes:
                        MPU_FLASH      (0): 0x00000000 -> 0x007fffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
                        MPU_SRAM       (1): 0x20400000 -> 0x2045ffff | PRIV_RWX_UNPRIV_RWX | W_BACK_NO_W_ALLOCATE | No Shareable | No Subregion Mask | Normal Memory
                        MPU_NOCACHE    (2): 0x20460000 -> 0x2046ffff | PRIV_RW_UNPRIV_RW   | NO_CACHE             | No Shareable | No Subregion Mask | Strong Order Memory
                        MPU_SHAREABLE  (3): 0x20470000 -> 0x2047ffff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Device Memory
                        MPU_RESULT     (4): 0x2046ff00 -> 0x2046ffff | PRIV_RWX_UNPRIV_RWX | NO_CACHE             | Shareable    | No Subregion Mask | Strong Order Memory
                    After, write access to address that belongs to MPU_SHAREABLE region. Expect to no enter the MemManage fault handler
            - Platform_Mpu_M7_SetRegionConfig
                    Change access permission for MPU_SHAREABLE region with PRIV_R_UNPRIV_R access permission
                    Then, write access to addresses that belongs to MPU_SHAREABLE region. Expect to enter the MemManage fault handler
            - Platform_Mpu_M7_EnableRegion
                    Enable/Disable MPU MPU_SHAREABLE region and need to check that:
                        Enter MemManage Fault handler while disabling MPU for MPU_SHAREABLE region
                        No enter MemManage Fault handler while enabling MPU for MPU_SHAREABLE region
            - Validation Point 
                    IsPassed = True (Verify that the Platform/MPU result returned corresponds to the expected value)

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - Daughter Board: XS32K396-BGA-DC PCB 54614 RevX1 SCH RevA
            - Motherboard: X-S32X-MB version A PCB 54935 RevX1 SCH RevA
            - Silicon: P32K396EHMJBS OP40E QAD2222F
        2.1.2 Connections
            - Powered board through power Adapter 12V
        2.1.3 Debugger
            - The debugger must be connected to J20 20-pin JTAG Cortex Debug connector.
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
            - TRESOS_DIR the installation path of the Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos/29.0.0
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = D:/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
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
