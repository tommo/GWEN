io.stdout:setvbuf("no")

MOAISim.openWindow( 'gwen', 800, 500 )
local layer = MOAILayer.new()
local viewport = MOAIViewport.new ()
viewport:setSize ( 800, 500 )
viewport:setScale ( 800, 500 )
layer:setViewport( viewport )
function bindMouseInput( sys )
	local x0, y0
	local function onMouseLeftEvent ( down )
		return sys:sendMouseButtonEvent( 0, down )
	end

	local function onMouseRightEvent ( down )
		return sys:sendMouseButtonEvent( 1, down )
	end

	local function onMouseMiddleEvent ( down )
		return sys:sendMouseButtonEvent( 2, down )
	end

	local function onMouseMoveEvent ( x, y )
		x, y = layer:wndToWorld( x, y )
		x, y = sys:worldToModel( x, y )
		y = - y
		local dx, dy
		if x0 then
			dx = x - x0
			dy = y - y0
		else
			dx, dy = 0,0
		end
		x0, y0 = x, y
		return sys:sendMouseMoveEvent( x, y, dx, dy )
	end

	MOAIInputMgr.device.mouseLeft:setCallback ( onMouseLeftEvent )
	MOAIInputMgr.device.mouseRight:setCallback ( onMouseRightEvent )
	MOAIInputMgr.device.pointer:setCallback ( onMouseMoveEvent )
end

MOAIRenderMgr.setBufferTable( { MOAIGfxDevice.getFrameBuffer() } )
MOAIGfxDevice.getFrameBuffer():setRenderTable( { layer } )

font = MOAIFont.new ()
font:load ( "droid.ttf" )
font:setDefaultSize( 12 )
font:getCache():setColorFormat( MOAIImage.COLOR_FMT_RGBA_8888 )
font:getReader():setPenColor( 1,1,1,1 )
MOAIGwenMgr.registerFont( 'droid',  font )

skin = MOAIGwenSkinTexturedBase.new()
skin:init( 'DefaultSkin.png' )
skin:setDefaultFont( 'droid', 12 )

sys = MOAIGwenSystem.new()
sys:setLoc( -400, 0 )
sys:setSkin( skin )
sys:start()
bindMouseInput( sys )

layer:insertProp( sys )

canvas = sys:getCanvas()
canvas:setName( 'canvas-root' )
canvas:setSize( 500, 500 )

dock = MOAIGwenDockBase.new()
dock:setBackgroundVisible( true )
dock:setSize( 500, 500 )
canvas:addChild( dock )
dock:setDock( MOAIGwenControl.POS_FILL )

center = dock:addChild( MOAIGwenLayoutPosition.new() )
center:setDock(  MOAIGwenControl.POS_FILL )
clist = dock:addChild( MOAIGwenCollapsibleList.new() )
clist:setSize( 200, 200 )
local cat = clist:addCategory( 'Basic' )
cat:add( 'Button' )
cat:add( 'Label' )
local cat = clist:addCategory( 'Non-Interactive' )
cat:add( 'PregressBar' )
cat:add( 'GroupBox' )
cat:add( 'ImagePanel' )
cat:add( 'StatusBar' )
local cat = clist:addCategory( 'Controls' )
local cat = clist:addCategory( 'Containers' )


-- cross = canvas:addChild( MOAIGwenCrossSplitter.new() )
-- cross:setSize( 500, 500 )
-- local text1 = MOAIGwenTextBox.new()
-- text1:setSize( 300, 300 )
-- text1:setText( 'hello' )
-- local text2 = MOAIGwenTextBox.new()
-- text2:setSize( 300, 300 )
-- text2:setText( 'from' )
-- local text3 = MOAIGwenTextBox.new()
-- text3:setSize( 300, 300 )
-- text3:setText( 'the' )
-- local text4 = MOAIGwenTextBox.new()
-- text4:setSize( 300, 300 )
-- text4:setText( 'hell' )
-- cross:setPanel( 1, text1 )
-- cross:setPanel( 2, text2 )
-- cross:setPanel( 3, text3 )
-- cross:setPanel( 4, text4 )
-- MOAICoroutine.new():run( function()
-- 		local t = 1
-- 		while t > 0 do t = t - coroutine.yield() end
-- 		cross:zoom( 4 )
-- 	end
-- )

tree = canvas:addChild( MOAIGwenTreeControl.new() )
tree:setSize( 200, 200 )
nodeFood = tree:addNode( "food" )
nodeFood:addNode( "steak" )

nodeDrink = tree:addNode( "drink" )
nodeDrink:addNode( "coke" )
nodeDrink:addNode( "milk" )


window = canvas:addChild( MOAIGwenWindowControl.new() )
window:setSize( 200, 300 )
window:setPos( 100, 100 )
-- window:addChild( tree )

note = window:addChild( MOAIGwenTabControl.new() )
note:setSize( 200, 100 )

text1 = MOAIGwenTextBox.new()
text1:setText( 'No good!' )
text2 = MOAIGwenTextBox.new()
text2:setText( 'No Bad!' )

note:addPage( "好的", text1 )
note:addPage( "坏的", text2 )
