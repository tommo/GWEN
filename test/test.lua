io.stdout:setvbuf("no")

MOAISim.openWindow( 'gwen', 800, 500 )
local layer = MOAILayer.new()
local viewport = MOAIViewport.new ()
viewport:setSize ( 800, 500 )
viewport:setScale ( 800, 500 )
layer:setViewport( viewport )
print("???")

MOAIRenderMgr.setBufferTable( { MOAIGfxDevice.getFrameBuffer() } )
MOAIGfxDevice.getFrameBuffer():setRenderTable( { layer } )

sys = MOAIGwenSystem.new()
skin = MOAIGwenSkinSimple.new()
sys:setSkin( skin )

sys:start()
layer:insertProp( sys )
canvas = sys:getCanvas()

-- button = MOAIGwenButton.new()
-- canvas:addChild( button )

window = MOAIGwenWindowControl.new()
canvas:addChild( window )
window:setSize( 200, 200 )
-- window:addChild( button )

-- print( button:getSize() )
-- print( button:getPos() )
print( window:getTypeName() )
MOAICoroutine.new():run( function() 
	while true do
		coroutine.yield()
		window:setSize( math.cos( os.clock() * 100 ) * 100 + 100, 200 )
	end
end)


-- label = MOAIGwenLabel.new()
-- canvas:addChild( label )
-- button:setText( 'Event Tester' )
-- button:addHandler( button.ON_PRESS, function( event, data ) print( 'button pressed' ) end )
