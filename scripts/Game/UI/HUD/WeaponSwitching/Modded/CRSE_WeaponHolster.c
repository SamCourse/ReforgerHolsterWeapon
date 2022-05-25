class CRSE_WeaponHolster: SCR_InfoDisplay {
	private InputManager inputManager;
	private SCR_CharacterControllerComponent characterController;
	private BaseWeaponManagerComponent weaponManager;
	private IEntity player;
	private BaseWeaponComponent lastWeapon;
	
	void CRSE_WeaponHolster(IEntity owner) {
		this.player = owner;
	}
	
	void Init() {
		characterController = SCR_CharacterControllerComponent.Cast(player.FindComponent(SCR_CharacterControllerComponent));
		this.registerEventListener();
	}

    void holsterKeyPressed() {
		if (!characterController || characterController.IsChangingItem())
			return;

		weaponManager = characterController.GetWeaponManagerComponent();
		if (!weaponManager)
			return;
		
		BaseWeaponComponent currentWeapon = weaponManager.GetCurrentWeapon();
		if (!currentWeapon) {
			this.unholsterWeapon();
		} else {
			this.holsterWeapon();
		}
    }
	
	private void holsterWeapon() {
		this.lastWeapon = weaponManager.GetCurrentSlot();
		characterController.SelectWeapon(null);
	}
	
	private void unholsterWeapon() {
		if (!this.lastWeapon)
			return;
		
		characterController.SelectWeapon(this.lastWeapon);
		this.lastWeapon = null;
	}
	
	
    void registerEventListener() {
        inputManager = GetGame().GetInputManager();
		
        if(!inputManager)
            return;
		
        inputManager.AddActionListener("CharacterHolsterWeapon", EActionTrigger.UP, holsterKeyPressed);
    }
	
    void unregisterEventListener() {
        inputManager.RemoveActionListener("CharacterHolsterWeapon", EActionTrigger.UP, holsterKeyPressed);
    }
}